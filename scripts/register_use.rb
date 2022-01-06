require 'pp';

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
    'dramtmg9' => "Should be configured even for DDR3",
    'pccfg' => "Only used when x16 width",
    'dramtmg12' => "Only used with PDA_EN",
    'ptr2' => "Should this be used?", 
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

totused = platforms.map{|p| reguse[p]}.flatten.uniq.sort
refregs = regs.map{|rg| rg[:regs]}.flatten
puts "=== DDR registers not mapped to configuration registers"
puts
puts "[cols=\"1,5*^\"]"
puts "|==="
puts "| " + ["register"].concat(platforms).join(" | ") + " | comments"
puts
(totused - refregs).each do|rname|
    puts "| #{rname}"
    platforms.each do|p|
        puts reguse[p].include?(rname) ? "| yes" : "| -"
    end
    puts "| " + (comments[rname] ? comments[rname] : "")
end
