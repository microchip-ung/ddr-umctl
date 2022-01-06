require 'pp';

regs = [

    { :grp => "Main control registers",
      :regs => %w(mstr mrctrl0 mrctrl1 derateen derateint pwrctl pwrtmg
hwlpctl rfshctl0 rfshctl3 crcparctl0 zqctl0 dfitmg0 dfitmg1 dfilpcfg0
dfiupd0 dfiupd1 dfiupd2 dfiphymstr odtmap dbg0 dbg1 dbgcmd poisoncfg
pccfg)
    },

    { :grp => "Timing configuration registers",
      :regs => %w(rfshtmg dramtmg0 dramtmg1 dramtmg2 dramtmg3 dramtmg4 dramtmg5
dramtmg6 dramtmg7 dramtmg8 dramtmg14 odtcfg),
    },    

    { :grp => "Address map configuration registers",
      :regs => %w(addrmap1 addrmap2 addrmap3 addrmap4 addrmap5 addrmap6 addrmap9
addrmap10 addrmap11),
    },
    
    { :grp => "Performance configuration registers",
      :regs => %w(sched sched1 perfhpr1 perflpr1 perfwr1 pcfgr_0 pcfgw_0 pcfgqos0_0
pcfgqos1_0 pcfgwqos0_0 pcfgwqos1_0 pcfgr_1 pcfgw_1 pcfgqos0_1
pcfgqos1_1 pcfgwqos0_1 pcfgwqos1_1),
    },

    { :grp => "DDR PHY registers",
      :regs => %w(pgcr aciocr dxccr dsgcr dcr odtcr zq0cr1 dx0gcr dx1gcr dx2gcr dx3gcr),
    },

    { :grp => "DDR PHY timing registers",
      :regs => %w(ptr0 ptr1 ptr2 dtpr0 dtpr1 dtpr2 mr0 mr1 mr2 mr3),
    },

    { :grp => "DDR PHY calibration registers",
      :regs => %w(dx0dllcr dx0dqtr dx0dqstr dx1dllcr dx1dqtr dx1dqstr dx2dllcr
dx2dqtr dx2dqstr dx3dllcr dx3dqtr dx3dqstr),
    },
]

def read_trace(file)
    reguse = Hash.new
    File.open(file).each do |line|
        if data = line.match(/[Ww]([0-9a-f]{8,10})[,=]([0-9a-f]{8}) \((UMCTL2_REGS|DWC_DDRPHY_PUB|UMCTL2_MP)_(\w+)\)/)
            reguse[data[4].downcase] = true
        end
    end
    return reguse
end

r = Hash.new
r["fa ddr4"] = read_trace("trace/fireant_ddr4.txt")

platforms = r.keys.sort
regs.each do |rg|
    puts "=== #{rg[:grp]}"
    puts

    puts "[cols=\"1,1\"]"
    puts "|==="
    puts "| " + ["stm32mp1"].concat(platforms).join(" | ")
    puts
    rg[:regs].each do |rname|
        puts "| #{rname}"
        platforms.each do|p|
            puts r[p].include?(rname) ? "| yes " : "| - "
        end
    end
    puts "|==="
    puts
end
