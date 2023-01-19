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

def get_memory_profile(profile)
    profile = YAML::load_file(__dir__ + "/../configs/memory/#{profile}.yaml")
    return profile
end

def calc_value(reg, params)
    val = 0
    reg[:fields].each do|f|
        fname = f[:name].upcase
        fval = f[:default]
        if params.has_key?(fname)
            $l.debug "#{reg[:name]}: Set #{fname} = #{params[fname]} (default #{f[:default]})"
            fval = params[fname]
            params.delete(fname)
        end
        val += (fval << f[:pos])
    end
    # Check all fields used
    if params.length > 0
        raise "Unused fields for register #{reg[:name]}: #{params}"
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
    opts.on("-b", "--board <board>", "Use board tweak file") do |b|
        $option[:board] = b
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

params[:dq_bits_per_mem] = params[:CONFIGURED_DQ_BITS]

$l.debug "params = #{params}"

case params[:mem_type]
when "DDR3"
    params = ddr3(params)
when "DDR4"
    params = ddr4(params)
else
    raise "Unsupported memory type: #{params[:mem_type]}"
end

case params[:CONFIGURED_DENSITY]
when "2G"
    capacity = 2
when "4G"
    capacity = 4
when "8G"
    capacity = 8
when "16G"
    capacity = 16
else
    raise "Invalid CONFIGURED_DENSITY: #{params[:CONFIGURED_DENSITY]}"
end
params[:mem_size] = capacity * 1024 * 1024 * 1024

# Calculate derived settings
params = ddr_process(params)

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
reg_settings["INIT5"] = {
    "DEV_ZQINIT_X32"		=> ((params[:tZQinitc] / 2.0) / 32).ceil() + 1,
}
# init6
reg_settings["INIT6"]["MR5"] = params[:reg_ddrc_mr5]
# init7
reg_settings["INIT7"]["MR6"] = params[:reg_ddrc_mr6]
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
reg_settings["RFSHCTL0"]["REFRESH_BURST"] = 1
# rfshctl3
# dramtmg0
if params[:mem_type] == "DDR4"
    if params[:write_preamble] == 1
        wr2pre = ((params[:WL] + (params[:BL] / 2.0).to_i() + params[:tWRc] + 2 ) / 2.0).to_i() + params[:_2T_mode]
    else
        if params[:write_crc] == 1 && params[:dm_en] == 1
            wr2pre = ((params[:WL] + (params[:BL] / 2.0).to_i() + params[:tWRc_CRC_DM] + 2 ) / 2.0).to_i() + params[:_2T_mode]
        else
            wr2pre = ((params[:WL] + (params[:BL] / 2.0).to_i() + params[:tWRc]) / 2.0).to_i() + params[:_2T_mode]
        end
    end
else
    wr2pre = ((params[:WL] + (params[:BL] / 2.0).to_i() + params[:tWRc]) / 2.0).to_i() + params[:_2T_mode]
end
reg_settings["DRAMTMG0"] = {
    "WR2PRE"		=> wr2pre,
    "T_FAW"		=> (params[:tFAWc] / 2.0).ceil(),
    "T_RAS_MIN"		=> (params[:tRASc_min] / 2.0).to_i() + params[:_2T_mode],
    "T_RAS_MAX"		=> ((params[:tRASc_max] - 1) / (2.0 * 1024)).to_i(),
}
#  dramtmg1
reg_settings["DRAMTMG1"]["T_RC"] = (params[:tRCc] / 2.0).ceil()
if params[:mem_type] == "DDR4"
    if params[:ca_parity_en] == 0
        reg_settings["DRAMTMG1"]["T_XP"] = (params[:tXPc] / 2.0).ceil()
    else
        reg_settings["DRAMTMG1"]["T_XP"] = ((params[:tXPc] + params[:tPLc]) / 2.0).ceil()
    end
else
    reg_settings["DRAMTMG1"]["T_XP"] = (params[:tXPc] / 2.0).ceil()
end
reg_settings["DRAMTMG1"]["RD2PRE"] = ((params[:AL] + params[:tRTPc]) / 2.0).to_i() + params[:_2T_mode]
# dramtmg12
# dramtmg2
if params[:mem_type] == "DDR4"
    val_rd2wr = params[:RL] + (params[:BL] / 2.0).to_i() + 1 + params[:WR_PREAMBLE] - params[:WL]
    if params[:write_crc] == 1 && params[:dm_en] == 1
        val_wr2rd = params[:CWLc] + params[:tPLc] + (params[:BL] / 2.0).to_i() + params[:tWTRc_L_CRC_DM] + params[:write_preamble]
    else
        val_wr2rd = params[:CWLc] + params[:tPLc] + (params[:BL] / 2.0).to_i() + params[:tWTRc] + params[:write_preamble]
    end
    val_tCCD = (params[:tCCDc_L] / 2.0).ceil()
    val_tRRD = (params[:tRRDc_L] / 2.0).ceil()
else
    val_rd2wr = params[:RL] + (params[:BL] / 2.0).to_i() + 2 - params[:WL]
    val_wr2rd = params[:CWLc] + (params[:BL] / 2.0).to_i() + params[:tWTRc]
    val_tCCD = (params[:tCCDc] / 2.0).ceil()
    val_tRRD = (params[:tRRDc] / 2.0).ceil()
end
reg_settings["DRAMTMG2"] = {
    "WR2RD"		=> (val_wr2rd / 2.0).ceil(),
    "RD2WR"		=> (val_rd2wr / 2.0).ceil(),
}
if params[:mem_type] != "DDR3"
    reg_settings["DRAMTMG2"]["WRITE_LATENCY"] = (params[:WL] / 2.0).ceil()
    reg_settings["DRAMTMG2"]["READ_LATENCY"] = (params[:RL] / 2.0).ceil()
end
# dramtmg3
# dramtmg4
reg_settings["DRAMTMG4"] = {
  "T_RCD"		=> ((params[:tRCDc] - params[:AL]) / 2.0).ceil(),
  "T_RP"		=> (params[:tRPc] / 2.0).floor() + 1,
  "T_CCD"		=> val_tCCD,
  "T_RRD"		=> val_tRRD,
}
# dramtmg5
reg_settings["DRAMTMG5"] = {
  "T_CKSRX"		=> (params[:tCKSRXc] / 2.0).ceil(),
  "T_CKSRE"		=> (params[:tCKSREc] / 2.0).ceil(),
  "T_CKESR"		=> ((params[:tCKEc] + 1) / 2.0).ceil(),
  "T_CKE"		=> (params[:tCKEc] / 2.0).ceil(),
}
# dramtmg8
reg_settings["DRAMTMG8"] = {
    "T_XS_DLL_X32"	=> (params[:tDLLKc] / (2.0 * 32)).ceil(),
    "T_XS_X32"		=> (params[:tXS_tRFCc] / (2.0 * 32)).ceil(),
}
if params[:mem_type] == "DDR4"
    reg_settings["DRAMTMG8"]["T_XS_FAST_X32"] = (params[:tXS_tRFC4c] / (2.0 * 32)).ceil() + 1
    reg_settings["DRAMTMG8"]["T_XS_ABORT_X32"] = (params[:tXS_tRFC4c] / (2.0 * 32)).ceil()
end
# dramtmg9
if params[:mem_type] == "DDR4"
    reg_settings["DRAMTMG9"] = {
        "DDR4_WR_PREAMBLE"	=> params[:write_preamble],
        "T_CCD_S"		=> ((params[:tCCDc_S] + 1) / 2.0).ceil(),
        "T_RRD_S"		=> (params[:tRRDc_S] / 2.0).ceil(),
    }
    if params[:write_crc] == 1 && params[:dm_en] == 1
        reg_settings["DRAMTMG0"]["WR2RD_S"] = ((params[:CWLc] + params[:tPLc] + int(params[:BL] / 2.0)  + params[:tWTRc_S_CRC_DM] + params[:write_preamble]) / 2.0).ceil()
    else
        reg_settings["DRAMTMG9"]["WR2RD_S"] = ((params[:CWLc] + params[:tPLc] + (params[:BL] / 2.0).to_i() + params[:tWTRc_S] + params[:write_preamble]) / 2.0).ceil()
    end
end
# odtcfg
if params[:mem_type] == "DDR4"
    reg_settings["ODTCFG"] = {
        "WR_ODT_HOLD"	=> 5 + params[:WR_PREAMBLE] + params[:write_crc],
        "WR_ODT_DELAY"	=> params[:tCAL],
        "RD_ODT_HOLD"	=> 5 + params[:RD_PREAMBLE],
        "RD_ODT_DELAY"	=> params[:CLc] - params[:CWLc] - params[:RD_PREAMBLE] + params[:WR_PREAMBLE] + params[:tCAL],
    }
else
    reg_settings["ODTCFG"] = {
        "WR_ODT_HOLD" 	=> 0x6,
        "WR_ODT_DELAY"	=> 0x0,
        "RD_ODT_HOLD"	=> 0x6,
        "RD_ODT_DELAY"	=> params[:CLc] - params[:CWLc],
    }
end
# rfshtmg
if params[:mem_type] == "DDR4"
    reg_settings["RFSHTMG"]["T_RFC_NOM_X32"] = (params[:tREFIc] / (2.0 * 32)).to_i() # tRFEI (7.8 us) ((7800000 / itck) / (2 * 32))
else
    reg_settings["RFSHTMG"]["T_RFC_NOM_X32"] = 0x82 # tRFEI (7.8 us) ((7800000 / 2) / itck * 32) where itck = 938 ps
end
reg_settings["RFSHTMG"]["T_RFC_MIN"] = (params[:tRFCc] / 2.0).ceil()
# addrmap*
# - Defined by memory type profile
# dxccr
if params[:active_ranks] == 1
    reg_settings["DXCCR"]["RKLOOP"] = 0 # Not needed if only 1 rank
end
# dsgcr
# dcr
reg_settings["DCR"]["DDRMD"] = (params[:mem_type] == "DDR4" ? 4 : 3) # DDR3 = 3'b011 and DDR4 = 3'b100
reg_settings["DCR"]["DDR2T"] = params[:_2T_mode]
# dtcr0
reg_settings["DTCR0"]["DTRPTN"] = 15
reg_settings["DTCR0"]["DTMPR"] = 1
# dtcr1
reg_settings["DTCR1"]["RANKEN"] = params[:active_ranks]
# pgcr2
reg_settings["PGCR2"]["TREFPRD"] = params[:tRASc_max] - 400
# schcr1
if params[:active_ranks] > 1
    reg_settings["SCHCR1"]["ALLRANK"] = 1
end
# zq0pr
# zq1pr
# zq2pr
# zqcr
if ((params[:tCK_min] * 2) <= 2000)
    reg_settings["ZQCR"]["PGWAIT"] = 7;
else
    reg_settings["ZQCR"]["PGWAIT"] = 6;
end
# ptr0
reg_settings["PTR0"]["TPLLGS"] = params[:tpllgs]; #[format "%.0f" [expr int(4000/$params(ctl_clk_period))]] ; # 4 us
reg_settings["PTR0"]["TPLLPD"] = params[:tpllpd]; #[format "%.0f" [expr int(1000/$params(ctl_clk_period))]] ; # 1 us
# ptr1
reg_settings["PTR1"]["TPLLLOCK"] = params[:tplllock]; #[format "%.0f" [expr int(100000/$params(ctl_clk_period))]] ; # 100 us
reg_settings["PTR1"]["TPLLRST"] = params[:tpllrst]; #[format "%.0f" [expr int(9000/$params(ctl_clk_period)])] ; # 9 us
# ptr2
# ptr3
reg_settings["PTR3"]["TDINIT0"] = params[:tdinit0]; # 500 us
reg_settings["PTR3"]["TDINIT1"] = params[:tXS_tRFCc];# (tRFC + 10 ns)
# ptr4
reg_settings["PTR4"]["TDINIT2"] = params[:tdinit2]; # 200 us
reg_settings["PTR4"]["TDINIT3"] = params[:tZQinitc]; # tZQinit
# dtpr0
reg_settings["DTPR0"] = {
    "TRTP"		=> params[:tRTPc],
    "TRP"		=> params[:tRPc],
    "TRAS"		=> params[:tRASc_min],
    "TRRD"		=> params[:tRRDc],
}
# dtpr1
reg_settings["DTPR1"] = {
    "TMRD"		=> params[:tMRDc],
    "TMOD"		=> params[:tMOD],
    "TFAW"		=> params[:tFAWc],
    "TWLMRD"		=> params[:tWLMRDc],
}
# dtpr2
reg_settings["DTPR2"]["TXS"] = params[:tXS_tRFCc]
if params[:mem_type] == "DDR4"
    reg_settings["DTPR2"]["TCKE"] = params[:tCKEc]
else
    reg_settings["DTPR2"]["TCKE"] = params[:tCKEc] + 1
end
# dtpr3
reg_settings["DTPR3"]["TDLLK"] = params[:tDLLKc]
# dtpr4
if params[:mem_type] == "DDR4"
    reg_settings["DTPR4"]["TXP"] = params[:tXPc]
else
    reg_settings["DTPR4"]["TXP"] = params[:tXPDLLc]
end
reg_settings["DTPR4"]["TRFC"] = params[:tRFCc]
# dtpr5
reg_settings["DTPR5"] = {
    "TWTR"		=> params[:tWTRc],
    "TRCD"		=> params[:tRCDc],
    "TRC"		=> params[:tRCc],
}
# mr0
# mr1
# mr2
# mr3
# mr4
# mr5
# mr6
mr = Hash.new
if params[:mem_type] == "DDR4"
    mr["MR0"] = sprintf("0x%08x", params[:reg_ddrc_mr])
    mr["MR1"] = sprintf("0x%08x", params[:reg_ddrc_emr])
    mr["MR2"] = sprintf("0x%08x", params[:reg_ddrc_emr2])
    mr["MR3"] = sprintf("0x%08x", params[:reg_ddrc_emr3])
    mr["MR4"] = sprintf("0x%08x", params[:reg_ddrc_mr4])
    mr["MR5"] = sprintf("0x%08x", params[:reg_ddrc_mr5])
    mr["MR6"] = sprintf("0x%08x", params[:reg_ddrc_mr6])
else
    mr["MR0"] = sprintf("0x%08x", params[:reg_ddrc_mr])
    mr["MR1"] = sprintf("0x%08x", params[:reg_ddrc_emr])
    mr["MR2"] = sprintf("0x%08x", params[:reg_ddrc_emr2])
    mr["MR3"] = sprintf("0x%08x", params[:reg_ddrc_emr3])
end

if $option[:board]
    board = YAML::load_file(__dir__ + "/../configs/boards/#{$option[:board]}.yaml")
    board.each do |rname, flds|
        r = rname.upcase
        flds.each do |t|
            t.each do |f, v|
                if reg_settings[r][f]
                    $l.warn "#{r}: Board override #{f} from #{reg_settings[r][f]} => #{v}"
                end
                reg_settings[r][f] = v
            end
        end
    end
end

# Feed the chicken and go home
hex_values = convert_hex(cfg_regs, reg_settings)
p = get_memory_profile(params[:mem_profile])
p.each do |r, v|
    r = r.upcase
    v = sprintf("0x%08x", v)
    if hex_values[r]
        $l.warn "#{r}: Overide #{hex_values[r]} to #{v}"
    end
    hex_values[r] = v
end
# Add MR registers
hex_values = hex_values.merge(mr)

params[:version] = $option[:board] + " " +
                   Time.now.utc.strftime("%Y-%m-%d-%H:%M:%S") + " " +
                   %x( git describe --always --dirty --tags ).chop

renderer = ERB.new(File.read(__dir__ + "/templates/#{$option[:format]}.erb"), nil, '-')
puts renderer.result(binding)
