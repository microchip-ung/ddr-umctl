require 'pp'
require_relative 'soc/sparx5_soc.rb'

regs = [

    { :grp => "Main control registers",
      :regs => %w(mstr pwrctl
rfshctl0 rfshctl3 dfitmg0 dfitmg1 dfiupd0 dfiupd1 pccfg),
    },

    { :grp => "Timing configuration registers",
      :regs => %w(rfshtmg dramtmg0 dramtmg1 dramtmg2 dramtmg3 dramtmg4 dramtmg5
dramtmg8 dramtmg9 odtcfg),
    },    

    { :grp => "Address map configuration registers",
      :regs => %w(addrmap0 addrmap1 addrmap2 addrmap3 addrmap4 addrmap5 addrmap6 addrmap7 addrmap8),
    },
    
    { :grp => "DDR PHY registers",
      :regs => %w(dxccr dsgcr dcr),
    },

    { :grp => "DDR PHY timing registers",
      :regs => %w(ptr0 ptr1 ptr2 dtpr0 dtpr1 dtpr2 mr0 mr1 mr2 mr3),
    },

]

comments = {
    'dramtmg9' => "Should this be configured even for DDR3?",
    'pccfg' => "Only used for x16 width configurations",
    'dramtmg12' => "Only used with PDA_EN, do need this feature?",
    'ptr2' => "Should this be used?",
    'bistar0' => "Newly added (by JSA) for VREF training",
    'bistar1' => "-same-",
    'bistar3' => "-same-",
    'bistudpr' => "Newly added for VREF training",
    'crcparctl1' => "*Add config*: write_crc, ca_parity_en",
    'dbictl' => "*Add config*: dbi_en",
    'dfimisc' => "*Add config*: dbi_en",
    'dtcr0' => "*Add config*: depends on #lanes (dq_bits_used)",
    'dtcr1' => "*Add config*: depends params_active_ranks",
    'dtpr3' => "*Add config*: depends params_tDLLKc",
    'dtpr4' => "*Add config*: depends params_tXPc / params_tXPDLLc",
    'dtpr5' => "*Add config*: depends params_tWTRc / params_tRCDc / params_tRCc",
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
    'ecccfg0' => "*Add config*: ecc_mode",
    'eccpoisonaddr0' => "_Ignore_: Only used for ECC injection",
    'eccpoisonaddr1' => "_Ignore_: Only used for ECC injection",
    'init0' => "*Add config*: pre_cke / post_cke",
    'init1' => "*Add config*: DRAM_RSTN_X1024",
    'init3' => "*Add config*: params_reg_ddrc_mr / ddrc_emr",
    'init4' => "*Add config*: params_reg_ddrc_emr3 / ddrc_emr2",
    'init5' => "*Add config*: params_tZQinitc",
    'init6' => "*Add config*: params_reg_ddrc_mr5",
    'init7' => "*Add config*: params_reg_ddrc_mr6",
    'iovcr0' => "Fixed settings",
    'iovcr1' => "Fixed settings",
    'mr0_lpddr3' => "Alias for mr0_ddr4",
    'mr1_lpddr3' => "Alias for mr1_ddr4",
    'mr2_lpddr3' => "Alias for mr2_ddr4",
    'mr3_lpddr3' => "Alias for mr3_ddr4",
    'mr4_lpddr3' => "Alias for mr4_ddr4",
    'mr5_lpddr3' => "Alias for mr5_ddr4",
    'mr6_lpddr3' => "Alias for mr6_ddr4",
}

def read_trace(file)
    reguse = []
    File.open(file).each do |line|
        if data = line.match(/[Ww]([0-9a-f]{8,10})[,=]([0-9a-f]{8}) \((UMCTL2_REGS|DWC_DDRPHY_PUB|UMCTL2_MP)_(\w+)\)/)
            reguse << data[4].downcase
        end
    end
    return reguse.uniq
end

def read_tcl(file)
    reguse = []
    File.open(file).each do |line|
        if line.match(/^\s+erf_wr/) and
          data = line.match(/\s(DDR_UMCTL2|DDR_PHY)\s+(\w+)/)
            reguse << data[2].downcase
        end
    end
    return reguse.uniq
end

#sparx5 = Sparx5.new()

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
regs.each do |rg|
    puts "=== #{rg[:grp]}"
    puts

    puts "[cols=\"1,5*^\"]"
    puts "|==="
    puts "| " + ["registers"].concat(platforms).join(" | ") + " | comments"
    puts
    rg[:regs].each do |rname|
        puts "| #{rname}"
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
refregs = regs.map{|rg| rg[:regs]}.flatten
puts "=== Sparx5 DDR registers not mapped to configuration registers"
puts
puts "[cols=\"1,4*^\"]"
puts "|==="
puts "| " + ["register"].concat(platforms).join(" | ") + " | comments"
puts
(totused - refregs).each do|rname|
    puts "| #{rname}"
    platforms.each do|p|
        puts reguse[p].include?(rname) ? "| yes" : "| -"
    end
    #puts "| " + (sparx5.registers.include?(rname) ? "yes" : "no")
    puts "| " + (comments[rname] ? comments[rname] : "")
end
