require 'pp'
require_relative 'soc/sparx5_soc.rb'
require_relative 'config_registers.rb'

class Chip

    attr_reader :chip
    
    def initialize(chip)
        @chip = chip
    end

    def reggrp(regname)
        @chip.targets.each do|t|
            t[:groups].each do|g|
                if g[:registers].map{|r| r[:name]}.include?(regname)
                    return g[:name]
                end
            end
        end
        return "-unknown-"
    end

end


comments = {
    'dramtmg9' => "Should this be configured even for DDR3?",
    'pccfg' => "Only used for x16 width configurations",
    'dramtmg12' => "Only used with PDA_EN, do need this feature?",
    'ptr2' => "Should this be used?",
    'bistar0' => "VREF training",
    'bistar1' => "VREF training",
    'bistar3' => "VREF training",
    'bistudpr' => "VREF training",
    'crcparctl1' => "write_crc, ca_parity_en",
    'dbictl' => "dbi_en",
    'dfimisc' => "dbi_en",
    'dtcr0' => "depends on #lanes (dq_bits_used)",
    'dtcr1' => "depends params_active_ranks",
    'dtpr3' => "depends params_tDLLKc",
    'dtpr4' => "depends params_tXPc / params_tXPDLLc",
    'dtpr5' => "depends params_tWTRc / params_tRCDc / params_tRCc",
    'dx0gtr0' => "Fixed value: DGSL = 2 used, should it ever changed?",
    'dx1gtr0' => "Fixed value: DGSL = 2 used, should it ever changed?",
    'dx2gtr0' => "Fixed value: DGSL = 2 used, should it ever changed?",
    'dx3gtr0' => "Fixed value: DGSL = 2 used, should it ever changed?",
    'dx4gtr0' => "Fixed value: DGSL = 2 used, should it ever changed?",
    'dx0bdlr0' => "Used for data training (fixed value)",
    'dx0bdlr1' => "Used for data training (fixed value)",
    'dx0bdlr2' => "Used for data training (fixed value)",
    'dx1bdlr0' => "Used for data training (fixed value)",
    'dx1bdlr1' => "Used for data training (fixed value)",
    'dx1bdlr2' => "Used for data training (fixed value)",
    'dx2bdlr0' => "Used for data training (fixed value)",
    'dx2bdlr1' => "Used for data training (fixed value)",
    'dx2bdlr2' => "Used for data training (fixed value)",
    'dx3bdlr0' => "Used for data training (fixed value)",
    'dx3bdlr1' => "Used for data training (fixed value)",
    'dx3bdlr2' => "Used for data training (fixed value)",
    'dx4bdlr0' => "Used for data training (fixed value)",
    'dx4bdlr1' => "Used for data training (fixed value)",
    'dx4bdlr2' => "Used for data training (fixed value)",
    'dx0gcr5' => "Fixed value: Used for VDDQ",
    'dx1gcr5' => "Fixed value: Used for VDDQ",
    'dx2gcr5' => "Fixed value: Used for VDDQ",
    'dx3gcr5' => "Fixed value: Used for VDDQ",
    'dx4gcr5' => "Fixed value: Used for VDDQ",
    'dx2gcr0' => "Only used for x16 width configurations",
    'dx3gcr0' => "Only used for x16 width configurations",
    'dx4gcr0' => "Only used for x16 width configurations",
    'ecccfg0' => "ecc_mode",
    'eccpoisonaddr0' => "_Ignore_: Only used for ECC injection",
    'eccpoisonaddr1' => "_Ignore_: Only used for ECC injection",
    'init0' => "pre_cke / post_cke",
    'init1' => "DRAM_RSTN_X1024",
    'init3' => "params_reg_ddrc_mr / ddrc_emr",
    'init4' => "params_reg_ddrc_emr3 / ddrc_emr2",
    'init5' => "params_tZQinitc",
    'init6' => "params_reg_ddrc_mr5",
    'init7' => "params_reg_ddrc_mr6",
    'iovcr0' => "Fixed settings",
    'iovcr1' => "Fixed settings",
    'mr0' => "params_reg_ddrc_mr",
    'mr1' => "ddrc_emr",
    'mr2' => "ddrc_emr2",
    'mr3' => "params_reg_ddrc_emr3",
    'mr4' => "params_reg_ddrc_mr4",
    'mr5' => "dbi_en / params_dm_en / params_reg_ddrc_mr5",
    'mr6' => "params_reg_ddrc_mr6",
    'pctrl_0' => "Control only (ECC scrubbing)",
    'pgcr0' => "Control only",
    'pgcr1' => "Fixed settings",
    'pgcr2' => "params_tRASc_max",
    'pgcr3' => "Fixed settings, but *used* to hold params params_rd_dbi_en / params_wr_dbi_en (TCL script)",
    'pgcr7' => "Fixed settings",
    'pir' => "Fixed settings / depending on DDR3/DDR4",
    'ptr3' => "params_tdinit0 / params_tXS_tRFCc",
    'ptr4' => "params_tdinit2 / params_tZQinitc",
    'rankctl' => "Fixed settings",
    'rankidr' => "Index register for `DX*GTR0` etc",
    'rfshctl1' => "Fixed settings",
    'sbrctl' => "Used for ECC scrubbing init",
    'sbrwdata0' => "Used for ECC scrubbing init",
    'schcr1' => "params_active_ranks > 1",
    'swctl' => "Control only",
    'vtcr0' => "Fixed settings",
    'vtcr1' => "Fixed settings",
    'zq0pr' => "ddrconf->ca_ln_drv : ddrconf->zqdiv",
    'zq1pr' => "ddrconf->zqdiv",
    'zq2pr' => "ddrconf->zqdiv",
    'zqcr' => "asym_drv_pd/pu and params_tCK_min",
}

def read_trace(file)
    reguse = []
    File.open(file).each do |line|
        if data = line.match(/[Ww]([0-9a-f]{8,10})[,=]([0-9a-f]{8}) \((UMCTL2_REGS|DWC_DDRPHY_PUB|UMCTL2_MP)_(\w+)\)/)
            reg = data[4].downcase
            reg.gsub!(/^(mr\d)_.+/, '\1')
            reguse << reg
        end
    end
    return reguse.uniq
end

def read_tcl(file)
    reguse = []
    File.open(file).each do |line|
        if line.match(/^\s+erf_wr/) and
          data = line.match(/\s(DDR_UMCTL2|DDR_PHY)\s+(\w+)/)
            reg = data[2].downcase
            reg.gsub!(/^(mr\d)_.+/, '\1')
            reguse << reg
        end
    end
    return reguse.uniq
end

sparx5 = Sparx5.new()
chip = Chip.new(sparx5)
config = Config.new()

reguse = Hash.new
reguse["stm32mp1"] = %w(
mstr mrctrl0 mrctrl1 derateen derateint pwrctl pwrtmg
hwlpctl rfshctl0 rfshctl3 crcparctl0 zqctl0 dfitmg0 dfitmg1 dfilpcfg0
dfiupd0 dfiupd1 dfiupd2 dfiphymstr odtmap dbg0 dbg1 dbgcmd poisoncfg
pccfg
rfshtmg dramtmg0 dramtmg1 dramtmg2 dramtmg3 dramtmg4 dramtmg5
dramtmg6 dramtmg7 dramtmg8 dramtmg14 odtcfg
addrmap1 addrmap2 addrmap3 addrmap4 addrmap5 addrmap6 addrmap9 addrmap10 addrmap11
sched sched1 perfhpr1 perflpr1 perfwr1 pcfgr_0 pcfgw_0 pcfgqos0_0
pcfgqos1_0 pcfgwqos0_0 pcfgwqos1_0 pcfgr_1 pcfgw_1 pcfgqos0_1
pcfgqos1_1 pcfgwqos0_1 pcfgwqos1_1
pgcr aciocr dxccr dsgcr dcr odtcr zq0cr1 dx0gcr dx1gcr dx2gcr dx3gcr
ptr0 ptr1 ptr2 dtpr0 dtpr1 dtpr2 mr0 mr1 mr2 mr3
dx0dllcr dx0dqtr dx0dqstr dx1dllcr dx1dqtr dx1dqstr dx2dllcr
dx2dqtr dx2dqstr dx3dllcr dx3dqtr dx3dqstr
)
reguse["ddr tcl"] = read_tcl("trace/tcl_ddr.txt")
reguse["fa ddr3"] = read_trace("trace/fireant_ddr3.txt")
reguse["fa ddr4"] = read_trace("trace/fireant_ddr4.txt")

platforms = reguse.keys.sort
config.groups.each do |rg|
    puts "=== #{rg[:grp]}"
    puts

    puts "[cols=\"1,6*^\"]"
    puts "|==="
    puts "| " + ["register", "group"].concat(platforms).join(" | ") + " | comments"
    puts
    rg[:regs].sort.each do |rname|
        puts "| #{rname}"
        puts "| " + chip.reggrp(rname)
        platforms.each do|p|
            puts reguse[p].include?(rname) ? "| yes" : "| -"
        end
        puts "| " + (comments[rname] ? comments[rname] : "")
    end
    puts "|==="
    puts
end

# Drop stm32mp1 registers, since we don't exactly same set of registers
reguse.delete("stm32mp1")
platforms.delete("stm32mp1")

totused = platforms.map{|p| reguse[p]}.flatten.uniq.sort
refregs = config.groups.map{|rg| rg[:regs]}.flatten
puts "=== Sparx5 DDR registers not depending on configuration"
puts
puts "[cols=\"1,5*^\"]"
puts "|==="
puts "| " + ["register", "group"].concat(platforms).join(" | ") + " | comments"
puts
(totused - refregs).sort.each do|rname|
    puts "| #{rname}"
    puts "| " + chip.reggrp(rname)
    platforms.each do|p|
        puts reguse[p].include?(rname) ? "| yes" : "| -"
    end
    puts "| " + (comments[rname] ? comments[rname] : "")
end
