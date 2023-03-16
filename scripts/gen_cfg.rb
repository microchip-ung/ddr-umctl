#!/bin/env ruby

require 'optparse'
require 'erb'
require 'logger'
require 'pp'

require_relative 'soc/chip.rb'
require_relative 'ddr/ddr_process.rb'
require_relative 'ddr/ddr3.rb'
require_relative 'ddr/ddr4.rb'

def extract_field(f, val)
  v = (val >> f[:pos]) & ((1 << f[:width]) - 1)
  return v
end

class RegSettings
    attr_accessor :settings

    def initialize(soc)
        @soc = soc
        @settings = @soc.config.register_value_set()
    end

    def setting(reg, field)
        f = @settings[reg]
        return nil unless f
        return f[field]
    end

    def set(reg, field, value)
        $l.debug "Set field: #{reg}.#{field} = #{value}"
        if @settings.has_key?(reg)
            @settings[reg][field] = value
        else
            $l.error "Trying to set value #{reg}.#{field} in unknown register"
        end
    end

    def set_h(reg, fields)
        fields.each do |field, value|
            set(reg, field, value)
        end
    end

    def set_r(reg, value)
        creg = @soc.config.chip_registers[reg]
        if !creg
            $l.warn "Unknown reg #{reg}"
            return
        end
        creg[:fields].each do|f|
            fname = f[:name].upcase
            fval = extract_field(f, value)
            set(reg, fname, fval)
            $l.debug "Set field: #{reg}.#{fname} = #{fval}"
        end
    end
end

def apply_reg_settings(what, reg, r, f, v)
    if reg.setting(r, f)
        $l.warn "#{r}: #{what} #{f} from #{reg.setting(r, f)} => #{v}"
    else
        $l.debug "#{r}: #{what} #{f} => #{v}"
    end
    reg.set(r, f, v)
end

def apply_settings(file, what, reg)
    data = YAML::load_file(file)
    $l.debug "#{what}: Read #{file}"
    data.each do |rname, flds|
        r = rname.upcase
        if flds.is_a?(Array)
            flds.each do |t|
                t.each do |f, v|
                    apply_reg_settings(what, reg, r, f, v)
                end
            end
        elsif flds.is_a?(Hash)
            flds.each do |f, v|
                apply_reg_settings(what, reg, r, f, v)
            end
        else
            raise "#{what}: #{r}: Wrong type #{flds.class}"
        end
    end
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
        $l.debug "Unused fields for register #{reg[:name]}: #{params}"
    end
    return val
end

def convert_to_val(regs, settings)
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
            a = $soc.find(r)
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
    :debug	=> false,
    :verbose	=> false,
    :format	=> "devicetree",
}

$l = Logger.new(STDERR)
$l.formatter = proc do |severity, datetime, progname, msg|
    "#{severity}: #{msg}\n"
end

$l.level = Logger::WARN

OptionParser.new do |opts|
    opts.banner = "Usage: cfg_gen.rb [options] [config-file]"
    opts.version = 0.1
    opts.on("-d", "--debug", "Enable debug messages") do
        $option[:debug] = true
        $l.level = Logger::DEBUG
    end
    opts.on("-v", "--verbose", "Enable verbose messages") do
        $option[:verbose] = true
        $l.level = Logger::INFO
    end
    opts.on("-f", "--format <format>", %w(devicetree yaml source), "Use format (devicetree, yaml, source)") do |f|
        $option[:format] = f
    end
end.order!

def generate(file)

    # Load platform/memory parameters
    params = YAML::load_file(file)

    $l.debug "params = #{params}"

    # Prepare default values, registers, etc.
    $soc = Chip.new(params[:platform])

    reg = RegSettings.new($soc)

    case params[:mem_type]
    when "DDR3"
        if !params[:speed_grade]
            params[:speed_grade] = ddr3_find_speed_grade(params[:clock_speed])
            $l.debug "Found speed grade #{params[:speed_grade]} for speed #{params[:clock_speed]}"
        end
        params = ddr3(params)
    when "DDR4"
        if !params[:speed_grade]
            params[:speed_grade] = ddr4_find_speed_grade(params[:clock_speed])
            $l.debug "Found speed grade #{params[:speed_grade]} for speed #{params[:clock_speed]}"
        end
        # Always enable write CRC on DDR4
        params[:write_crc_en] = 1
        # Always enable CA parity on DDR4
        params[:ca_parity_mode] = 1
        params = ddr4(params)
    else
        raise "Unsupported memory type: #{params[:mem_type]}"
    end

    # Calculate derived settings
    params = ddr_process(params)

    # Now, generate actual register values
    # crcparctl1
    if params[:mem_type] == "DDR4"
        reg.set_h("CRCPARCTL1", {
                      "CRC_INC_DM"	=> params[:write_crc],
                      "CRC_ENABLE"	=> params[:write_crc],
                      "PARITY_ENABLE"	=> params[:ca_parity_en],
                  })
    end
    # dbictl
    if params[:mem_type] == "DDR4"
        reg.set_h("DBICTL", {
                      "DM_EN"		=> params[:dm_en],
                      "WR_DBI_EN"	=> params[:wr_dbi_en],
                      "RD_DBI_EN"	=> params[:rd_dbi_en],
                  })
    end
    # dfimisc
    reg.set("DFIMISC", "DFI_INIT_COMPLETE_EN", 0)
    # dfitmg0
    if params[:mem_type] == "DDR4"
        $l.info "DFITMG0: DDR4 WL = #{params[:WL]}, tCAL = #{params[:tCAL]}"
        reg.set_h("DFITMG0", {
                      "DFI_RDDATA_USE_DFI_PHY_CLK"	=> 1,
                      "DFI_WRDATA_USE_DFI_PHY_CLK"	=> 1,
                      "DFI_TPHY_WRLAT"		=> params[:WL] - 2 + params[:tCAL],
                      "DFI_T_RDDATA_EN"		=> params[:RL] - 4 + params[:tCAL],
                  })
    else
        $l.info "DFITMG0: DDR3 WL = #{params[:WL]}, RL = #{params[:RL]}"
        reg.set_h("DFITMG0", {
                      "DFI_TPHY_WRLAT"		=> params[:WL] - 2,
                      "DFI_T_RDDATA_EN"		=> params[:RL] - 4,
                  })
    end
    reg.set("DFITMG0", "DFI_TPHY_WRDATA", 0x2)
    reg.set("DFITMG0", "DFI_T_CTRL_DELAY", 0x3)
    reg.set("DFITMG0", "DFI_WRDATA_USE_DFI_PHY_CLK", 1)
    reg.set("DFITMG0", "DFI_RDDATA_USE_DFI_PHY_CLK", 1)
    # dfitmg1
    reg.set_h("DFITMG1", {
                  "DFI_T_DRAM_CLK_ENABLE"		=> 0x1,
                  "DFI_T_DRAM_CLK_DISABLE"		=> 0x2,
                  "DFI_T_WRDATA_DELAY"		=> 0x4,
              })
    if params[:mem_type] == "DDR4"
        reg.set("DFITMG1", "DFI_T_CMD_LAT", params[:tCAL])
    end
    # dfiupd0
    reg.set("DFIUPD0", "DIS_AUTO_CTRLUPD_SRX", 1)
    # dfiupd1
    reg.set("DFIUPD1", "DFI_T_CTRLUPD_INTERVAL_MIN_X1024", 0x40)
    reg.set("DFIUPD1", "DFI_T_CTRLUPD_INTERVAL_MAX_X1024", 0XFF)
    # ecccfg0
    # ECC Mode. 0x0 = ECC disabled, 0x4 = SECDED over 1 beat, 0x5 = Advance ECC
    if params[:ecc_mode] != 0
        if $soc.ecc_inline
            $l.debug "Inline ECC: Reducing memory to 7/8 of #{params[:mem_size_mbytes]}"
            params[:mem_size_mbytes] = 7 * (params[:mem_size_mbytes] / 8)
        end
        reg.set("ECCCFG0", "ECC_MODE", params[:ecc_mode])
    end
    # init0
    reg.set_h("INIT0", {
                  "PRE_CKE_X1024"		=> params[:pre_cke_x1024],
                  "POST_CKE_X1024"		=> params[:post_cke_x1024],
              })
    # init1
    reg.set_h("INIT1", {
                  "DRAM_RSTN_X1024"		=> params[:dram_rstn_x1024],
              })
    # init3
    reg.set_h("INIT3", {
                  "MR"			=> params[:reg_ddrc_mr],
                  "EMR"			=> params[:reg_ddrc_emr],
              })
    # init4
    reg.set_h("INIT4", {
                  "EMR2"			=> params[:reg_ddrc_emr2],
                  "EMR3"			=> params[:reg_ddrc_emr3],
              })
    # init5
    reg.set_h("INIT5", {
                  "DEV_ZQINIT_X32"		=> ((params[:tZQinitc] / 2.0) / 32).ceil() + 1,
              })
    # init6
    if params[:mem_type] == "DDR4"
        reg.set("INIT6", "MR4", params[:reg_ddrc_mr4])
        reg.set("INIT6", "MR5", params[:reg_ddrc_mr5])
    end
    # init7
    if params[:mem_type] == "DDR4"
        reg.set("INIT7", "MR6", params[:reg_ddrc_mr6])
    end
    # mstr
    reg.set_h("MSTR", {
                  "DDR3"			=> params[:mem_type] == "DDR3" ? 1 : 0,
                  "DDR4"			=> params[:mem_type] == "DDR4" ? 1 : 0,
                  "ACTIVE_RANKS"		=> params[:active_ranks],
                  "EN_2T_TIMING_MODE"	=> params[:_2T_mode],
              })
    if params[:mem_type] == "DDR4"
        devc_map = { "x8" => 1, "x16" => 2, "x32" => 3 }
        if devc = devc_map[params[:device_bus_width]]
            # MSTR.DEVICE_CONFIG only applies to DDR4
            reg.set("MSTR", "DEVICE_CONFIG", devc)
        end
    end
    if ($soc.bus_width % 16) == 0 && params[:enable_half_bus]
        $l.debug "Configuring half bus width"
        reg.set("MSTR", "DATA_BUS_WIDTH", 1)
        if params[:mem_type] == "DDR4"
            # pccfg
            # For optimum utilization of SDRAM, Burst length expansion mode is
            # enabled in case of Half bus width mode and UMCTL2_PARTIAL_WR =
            # 1, as per recommendation given in the uMCTL2 data book v2.70a
            # (pg. no. 122).
            reg.set("PCCFG", "BL_EXP_MODE", 1)
        end
    end
    # pwrctl
    # rfshctl0
    reg.set("RFSHCTL0", "REFRESH_BURST", 1)
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
    reg.set_h("DRAMTMG0", {
                  "WR2PRE"		=> wr2pre,
                  "T_FAW"		=> (params[:tFAWc] / 2.0).ceil(),
                  "T_RAS_MIN"		=> (params[:tRASc_min] / 2.0).to_i() + params[:_2T_mode],
                  "T_RAS_MAX"		=> ((params[:tRASc_max] - 1) / (2.0 * 1024)).to_i(),
              })
    #  dramtmg1
    reg.set("DRAMTMG1", "T_RC", (params[:tRCc] / 2.0).ceil())
    if params[:mem_type] == "DDR4"
        if params[:ca_parity_en] == 0
            reg.set("DRAMTMG1", "T_XP", (params[:tXPc] / 2.0).ceil())
        else
            reg.set("DRAMTMG1", "T_XP", ((params[:tXPc] + params[:tPLc]) / 2.0).ceil())
        end
    else
        reg.set("DRAMTMG1", "T_XP", (params[:tXPc] / 2.0).ceil())
    end
    reg.set("DRAMTMG1", "RD2PRE", ((params[:AL] + params[:tRTPc]) / 2.0).to_i() + params[:_2T_mode])
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
    reg.set_h("DRAMTMG2", {
                  "WR2RD"		=> (val_wr2rd / 2.0).ceil(),
                  "RD2WR"		=> (val_rd2wr / 2.0).ceil(),
              })
    if params[:mem_type] != "DDR3"
        reg.set("DRAMTMG2", "WRITE_LATENCY", (params[:WL] / 2.0).ceil())
        reg.set("DRAMTMG2", "READ_LATENCY", (params[:RL] / 2.0).ceil())
    end
    # dramtmg3
    # dramtmg4
    reg.set_h("DRAMTMG4", {
                  "T_RCD"		=> ((params[:tRCDc] - params[:AL]) / 2.0).ceil(),
                  "T_RP"		=> (params[:tRPc] / 2.0).floor() + 1,
                  "T_CCD"		=> val_tCCD,
                  "T_RRD"		=> val_tRRD,
              })
    # dramtmg5
    reg.set_h("DRAMTMG5", {
                  "T_CKSRX"		=> max(3, (params[:tCKSRXc] / 2.0).ceil()),
                  "T_CKSRE"		=> max(3, (params[:tCKSREc] / 2.0).ceil()),
                  "T_CKESR"		=> max(3, ((params[:tCKEc] + 1) / 2.0).ceil()),
                  "T_CKE"		=> max(3, (params[:tCKEc] / 2.0).ceil()),
              })
    # dramtmg8
    reg.set_h("DRAMTMG8", {
                  "T_XS_DLL_X32"	=> (params[:tDLLKc] / (2.0 * 32)).ceil(),
                  "T_XS_X32"		=> (params[:tXS_tRFCc] / (2.0 * 32)).ceil(),
              })
    if params[:mem_type] == "DDR4"
        reg.set("DRAMTMG8", "T_XS_FAST_X32", (params[:tXS_tRFC4c] / (2.0 * 32)).ceil() + 1)
        reg.set("DRAMTMG8", "T_XS_ABORT_X32", (params[:tXS_tRFC4c] / (2.0 * 32)).ceil())
        # Note currently unsure of the two above params for DDR3 - left as default for now
    end
    # dramtmg9
    if params[:mem_type] == "DDR4"
        reg.set_h("DRAMTMG9", {
                      "DDR4_WR_PREAMBLE"	=> params[:write_preamble],
                      "T_CCD_S"		=> ((params[:tCCDc_S] + 1) / 2.0).ceil(),
                      "T_RRD_S"		=> (params[:tRRDc_S] / 2.0).ceil(),
                  })
        if params[:write_crc] == 1 && params[:dm_en] == 1
            reg.set("DRAMTMG0", "WR2RD_S", ((params[:CWLc] + params[:tPLc] + (params[:BL] / 2.0).to_i()  + params[:tWTRc_S_CRC_DM] + params[:write_preamble]) / 2.0).ceil())
        else
            reg.set("DRAMTMG9", "WR2RD_S", ((params[:CWLc] + params[:tPLc] + (params[:BL] / 2.0).to_i() + params[:tWTRc_S] + params[:write_preamble]) / 2.0).ceil())
        end
    end
    # odtcfg
    if params[:mem_type] == "DDR4"
        reg.set_h("ODTCFG", {
                      "WR_ODT_HOLD"		=> 5 + params[:WR_PREAMBLE] + params[:write_crc],
                      "WR_ODT_DELAY"	=> params[:tCAL],
                      "RD_ODT_HOLD"		=> 5 + params[:RD_PREAMBLE],
                      "RD_ODT_DELAY"	=> params[:CLc] - params[:CWLc] - params[:RD_PREAMBLE] + params[:WR_PREAMBLE] + params[:tCAL],
                  })
    else
        reg.set_h("ODTCFG", {
                      "WR_ODT_HOLD" 	=> 0x6,
                      "WR_ODT_DELAY"	=> 0x0,
                      "RD_ODT_HOLD"	=> 0x6,
                      "RD_ODT_DELAY"	=> params[:CLc] - params[:CWLc],
                  })
    end
    # rfshtmg
    # This parameter has different names in different soc's
    fname = $soc.get_field_alternative("RFSHTMG", %w(T_RFC_NOM_X1_X32 T_RFC_NOM_X32))
    if params[:mem_type] == "DDR4"
        reg.set("RFSHTMG", fname, (params[:tREFIc] / (2.0 * 32)).to_i()) # tRFEI (7.8 us) ((7800000 / itck) / (2 * 32))
    else
        reg.set("RFSHTMG", fname, 0x82) # tRFEI (7.8 us) ((7800000 / 2) / itck * 32) where itck = 938 ps
    end
    reg.set("RFSHTMG", "T_RFC_MIN", (params[:tRFCc] / 2.0).ceil())
    # addrmap*
    # - Defined by memory type profile
    # dxccr
    if params[:active_ranks] == 1
        reg.set("DXCCR", "RKLOOP", 0) # Not needed if only 1 rank
    end
    # dsgcr
    # dcr
    reg.set("DCR", "DDRMD", (params[:mem_type] == "DDR4" ? 4 : 3)) # DDR3 = 3'b011 and DDR4 = 3'b100
    reg.set("DCR", "DDR2T", params[:_2T_mode])
    # Set DTCR
    if $soc.find("DTCR")
        $l.debug "Using simple PUB"
        reg.set("DTCR", "DTRPTN", 7)
        reg.set("DTCR", "DTMPR", 1)
        reg.set("DTCR", "RANKEN", (1 << params[:active_ranks]) - 1)
    else
        $l.debug "Using simple PUB training spans two registers"
        # dtcr0
        reg.set("DTCR0", "DTRPTN", 15)
        reg.set("DTCR0", "DTMPR", 1)
        # dtcr1
        reg.set("DTCR1", "RANKEN", (1 << params[:active_ranks]) - 1)
    end
    # pgcr2
    reg.set("PGCR2", "TREFPRD", params[:tREFIc] - 400)
    # schcr1
    if params[:active_ranks] > 1
        reg.set("SCHCR1", "ALLRANK", 1)
    end
    # zq0pr
    # zq1pr
    # zq2pr
    # zqcr
    if ((params[:tCK_min] * 2) <= 2000)
        reg.set("ZQCR", "PGWAIT", 7)
    else
        reg.set("ZQCR", "PGWAIT", 6)
    end
    # ptr0
    reg.set("PTR0", "TPLLGS", params[:tpllgs]) #[format "%.0f" [expr int(4000/$params(ctl_clk_period))]] ; # 4 us
    reg.set("PTR0", "TPLLPD", params[:tpllpd]) #[format "%.0f" [expr int(1000/$params(ctl_clk_period))]] ; # 1 us
    # ptr1
    reg.set("PTR1", "TPLLLOCK", params[:tplllock]) #[format "%.0f" [expr int(100000/$params(ctl_clk_period))]] ; # 100 us
    reg.set("PTR1", "TPLLRST", params[:tpllrst]) #[format "%.0f" [expr int(9000/$params(ctl_clk_period)])] ; # 9 us
    # ptr2
    # ptr3
    reg.set("PTR3", "TDINIT0", params[:tdinit0]) # 500 us
    reg.set("PTR3", "TDINIT1", params[:tXS_tRFCc])# (tRFC + 10 ns)
    # ptr4
    reg.set("PTR4", "TDINIT2", params[:tdinit2]) # 200 us
    reg.set("PTR4", "TDINIT3", params[:tZQinitc]) # tZQinit
    # dtpr0
    reg.set_h("DTPR0", {
                  "TRTP"		=> params[:tRTPc],
                  "TRP"		=> params[:tRPc],
                  "TRAS"		=> params[:tRASc_min],
                  "TRRD"		=> params[:tRRDc],
              })
    # dtpr1
    reg.set_h("DTPR1", {
                  "TMRD"		=> params[:tMRDc],
                  "TMOD"		=> params[:tMOD],
                  "TFAW"		=> params[:tFAWc],
                  "TWLMRD"		=> params[:tWLMRDc],
              })
    # dtpr2
    reg.set("DTPR2", "TXS", params[:tXS_tRFCc])
    if params[:mem_type] == "DDR4"
        reg.set("DTPR2", "TCKE", params[:tCKEc])
    else
        reg.set("DTPR2", "TCKE", params[:tCKEc] + 1)
    end
    # dtpr3
    reg.set("DTPR3", "TDLLK", params[:tDLLKc])
    # dtpr4
    if params[:mem_type] == "DDR4"
        reg.set("DTPR4", "TXP", params[:tXPc])
    else
        reg.set("DTPR4", "TXP", params[:tXPDLLc])
    end
    reg.set("DTPR4", "TRFC", params[:tRFCc])
    # dtpr5
    reg.set_h("DTPR5", {
                  "TWTR"		=> params[:tWTRc],
                  "TRCD"		=> params[:tRCDc],
                  "TRC"		=> params[:tRCc],
              })

    if params[:board]
        apply_settings(__dir__ + "/../configs/boards/#{params[:board]}.yaml", "Board override", reg)
    end

    if params[:mem_profile]
        apply_settings(__dir__ + "/../configs/memory/#{params[:mem_profile]}.yaml", "Memory setup", reg)
    end

    # Feed the chicken and go home
    reg_values = convert_to_val($soc.config.chip_registers, reg.settings)

    file_basename = File.basename(file, ".*")

    params[:version] = file_basename + " " +
                       Time.now.utc.strftime("%Y-%m-%d-%H:%M:%S") + " " +
                       %x( git describe --always --dirty --tags ).chop

    info = { 'version'   => params[:version],
             'speed'     => params[:clock_speed],
             'mem_size_mb' => params[:mem_size_mbytes],
             'bus_width' => $soc.bus_width,
             'platform'  => $soc.name,
           }
    data = { 'info' => info, 'config' => reg_values.transform_keys(&:downcase) }
    renderer = ERB.new(File.read(__dir__ + "/templates/#{$option[:format]}.erb"), nil, '-')
    puts renderer.result(binding)
end

ARGV.each do |f|
    generate(f)
end
