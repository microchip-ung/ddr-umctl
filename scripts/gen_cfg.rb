#!/bin/env ruby

require 'optparse'
require 'erb'
require 'logger'
require 'pp'

require_relative 'config_registers.rb'
require_relative 'soc/chip.rb'
require_relative 'ddr/ddr_process.rb'
require_relative 'ddr/ddr3.rb'
require_relative 'ddr/ddr4.rb'

def calc_value(reg, params)
    val = 0
    reg[:fields].each do|f|
        fname = f[:name].upcase
        fval = f[:default]
        if params.has_key?(fname)
            $l.debug "#{reg[:name]}: Set #{fname} = #{params[fname]}"
            fval = params[fname]
        end
        val += (fval << f[:pos])
    end
    return sprintf("0x%08x", val)
end

def convert_hex(regs, settings)
    values = Hash.new
    regs.each do|r, f|
        values[r] = calc_value(f, settings[r])
    end
    return values
end

def get_config_regs()
    regs = Hash.new
    $config.groups.each do|rg|
        rg[:regs].each do|r|
            a = $chip.find(r)
            if a
                regs[r] = a[2]
            else
                raise "Unknown reg #{r}"
            end
        end
    end
    return regs
end

# Parse options
$option = {
    :platform	=> "sparx5",
    :memory	=> "ddr4_ref",
    :debug	=> false,
    :verbose	=> false,
    :format	=> "devicetree",
}

$l = Logger.new(STDERR)
$l.level = Logger::WARN

OptionParser.new do |opts|
    opts.banner = "Usage: cfg_gen.rb [options]"
    opts.version = 0.1
    opts.on("-p", "--platform <platform>", "Generate for given platform") do |p|
        $option[:platform] = p
    end
    opts.on("-m", "--memory <memory>", "Generate for given memory parameters set") do |m|
        $option[:memory] = m
    end
    opts.on("-d", "--debug", "Enable debug messages") do
        $option[:debug] = true
        $l.level = Logger::DEBUG
    end
    opts.on("-v", "--verbose", "Enable verbose messages") do
        $option[:verbose] = true
        $l.level = Logger::INFO
    end
    opts.on("-f", "--format <format>", %w(devicetree yaml), "Use format (devicetree, yaml)") do |f|
        $option[:format] = f
    end
end.order!

# Prepare default values, registers, etc.
$config = Config.new()
$chip = Chip.new($option[:platform])

cfg_regs = get_config_regs()
reg_settings = Hash.new
cfg_regs.keys.map {|r| reg_settings[r.upcase] = Hash.new }

# Load platform/memory parameters
params = YAML::load_file(__dir__ + "/profiles/#{$option[:platform]}.yaml")
params.merge!(YAML::load_file(__dir__ + "/profiles/#{$option[:memory]}.yaml"))

if params[:clock_speed] >= (4 * 625)
    params[:clk_div] = 4
elsif params[:clock_speed] >= (4 * 500)
    params[:clk_div] = 5
elsif params[:clock_speed] >= (4 * 416)
    params[:clk_div] = 6
elsif params[:clock_speed] >= (4 * 312)
    params[:clk_div] = 8
elsif params[:clock_speed] >= (4 * 250)
    params[:clk_div] = 10
elsif params[:clock_speed] >= (4 * 208)
    params[:clk_div] = 12
elsif params[:clock_speed] >= (4 * 156)
    params[:clk_div] = 16
elsif params[:clock_speed] >= (4 * 125)
    params[:clk_div] = 20
else
    raise "Invalid clock: #{params[:clock_speed]}"
end

params[:dq_bits_per_mem] = params[:CONFIGURED_DQ_BITS]

case params[:mem_type]
when "DDR3"
    params = ddr3(params)
when "DDR4"
    params = ddr4(params)
else
    raise "Unsupported memory type: #{params[:mem_type]}"
end

# Calculate derived settings
params = ddr_process(params)

# Static settings
params[:_2T_mode] = 1

# Now, generate actual register values
# crcparctl1
if params[:mem_type] == "DDR4"
    reg_settings["CRCPARCTL1"] = {
        "CRC_INC_DM"		=> params[:write_crc],
        "CRC_ENABLE"		=> params[:write_crc],
        "PARITY_ENABLE"		=> params[:ca_parity_en],
    }
end
# dbictl
if params[:mem_type] == "DDR4"
    reg_settings["DBICTL"] = {
        "DM_EN"			=> params[:dm_en],
        "WR_DBI_EN"		=> params[:wr_dbi_en],
        "RD_DBI_EN"		=> params[:rd_dbi_en],
    }
end
# dfimisc
reg_settings["DFIMISC"]["DFI_INIT_COMPLETE_EN"] = 0
# dfitmg0
if params[:mem_type] == "DDR4"
    $l.info "DFITMG0: DDR4 WL = #{params[:WL]}, tCAL = #{params[:tCAL]}"
    reg_settings["DFITMG0"] = {
        "DFI_RDDATA_USE_DFI_PHY_CLK"	=> 1,
        "DFI_WRDATA_USE_DFI_PHY_CLK"	=> 1,
        "DFI_TPHY_WRLAT"		=> params[:WL] - 2 + params[:tCAL],
        "DFI_T_RDDATA_EN"		=> params[:RL] - 4 + params[:tCAL],
    }
else
    $l.info "DFITMG0: DDR3 WL = #{params[:WL]}, RL = #{params[:RL]}"
    reg_settings["DFITMG0"] = {
        "DFI_TPHY_WRLAT"		=> params[:WL] - 2,
        "DFI_T_RDDATA_EN"		=> params[:RL] - 4,
    }
end
reg_settings["DFITMG0"]["DFI_TPHY_WRDATA"] = 0x2
reg_settings["DFITMG0"]["DFI_T_CTRL_DELAY"] = 0x3
reg_settings["DFITMG0"]["DFI_WRDATA_USE_DFI_PHY_CLK"] = 1
reg_settings["DFITMG0"]["DFI_RDDATA_USE_DFI_PHY_CLK"] = 1
# dfitmg1
reg_settings["DFITMG1"] = {
    "DFI_T_DRAM_CLK_ENABLE"		=> 0x1,
    "DFI_T_DRAM_CLK_DISABLE"		=> 0x2,
    "DFI_T_WRDATA_DELAY"		=> 0x4,
}
if params[:mem_type] == "DDR4"
    reg_settings["DFITMG1"]["DFI_T_CMD_LAT"] = params[:tCAL]
end
# dfiupd0
reg_settings["DFIUPD0"]["DIS_AUTO_CTRLUPD_SRX"] = 1
# dfiupd1
reg_settings["DFIUPD1"]["DFI_T_CTRLUPD_INTERVAL_MIN_X1024"] = 0x40
reg_settings["DFIUPD1"]["DFI_T_CTRLUPD_INTERVAL_MAX_X1024"] = 0XFF
# ecccfg0
# ECC Mode. 0x0 = ECC disabled, 0x4 = SECDED over 1 beat, 0x5 = Advance ECC
reg_settings["ECCCFG0"]["ECC_MODE"] = 4
# init0
reg_settings["INIT0"] = {
    "PRE_CKE_X1024"		=> params[:pre_cke_x1024],
    "POST_CKE_X1024"		=> params[:post_cke_x1024],
}
# init1
reg_settings["INIT1"] = {
    "DRAM_RSTN_X1024"		=> params[:dram_rstn_x1024],
}
# init3
reg_settings["INIT3"] = {
    "MR"			=> params[:reg_ddrc_mr],
    "EMR"			=> params[:reg_ddrc_emr],
}
# init4
reg_settings["INIT4"] = {
    "EMR2"			=> params[:reg_ddrc_emr2],
    "EMR3"			=> params[:reg_ddrc_emr3],
}
# init5
# init6
# init7
# mstr
reg_settings["MSTR"] = {
    "DDR3"		=> params[:mem_type] == "DDR3" ? 1 : 0,
    "DDR4"		=> params[:mem_type] == "DDR4" ? 1 : 0,
    "ACTIVE_RANKS"	=> params[:active_ranks],
    "EN_2T_TIMING_MODE"	=> params[:_2T_mode],
    "DEVICE_CONFIG"	=> params[:device_config],
}
if params[:dq_bits_used] == "x16"
    reg_settings["MSTR"]["DATA_BUS_WIDTH"] = 1
end
# pccfg
if params[:dq_bits_used] == "x16"
    # For optimum utilization of SDRAM, Burst length expansion mode is
    # enabled in case of Half bus width mode and UMCTL2_PARTIAL_WR =
    # 1, as per recommendation given in the uMCTL2 data book v2.70a
    # (pg. no. 122).
    reg_settings["PCCFG"]["BL_EXP_MODE"] = 1
end
# pwrctl
# rfshctl0
# rfshctl3

# Feed the chicken and go home
hex_values = convert_hex(cfg_regs, reg_settings)
renderer = ERB.new(File.read(__dir__ + "/templates/#{$option[:format]}.erb"), nil, '-')
puts renderer.result(binding)
