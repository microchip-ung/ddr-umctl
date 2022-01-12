class Config

    attr_reader :groups, :registers

    def initialize()
        @groups = [

            { :grp => "Main control registers",
              :name => 'main',
              :regs => %w(mstr pwrctl
rfshctl0 rfshctl3 dfitmg0 dfitmg1 dfiupd0 dfiupd1 pccfg crcparctl1 dbictl dfimisc ecccfg0
init0 init1 init3 init4 init5 init6 init7),
            },

            { :grp => "Timing configuration registers",
              :name => 'timing',
              :regs => %w(rfshtmg dramtmg0 dramtmg1 dramtmg2 dramtmg3 dramtmg4 dramtmg5
dramtmg8 dramtmg9 dramtmg12 odtcfg),
            },

            { :grp => "Address map configuration registers",
              :name => 'mapping',
              :regs => %w(addrmap0 addrmap1 addrmap2 addrmap3 addrmap4 addrmap5 addrmap6 addrmap7 addrmap8),
            },

            { :grp => "DDR PHY registers",
              :name => 'phy',
              :regs => %w(dxccr dsgcr dcr dtcr0 dtcr1 pgcr2 schcr1 zq0pr zq1pr zq2pr zqcr),
            },

            { :grp => "DDR PHY timing registers",
              :name => 'phy_timing',
              :regs => %w(ptr0 ptr1 ptr2 ptr3 ptr4 dtpr0 dtpr1 dtpr2 dtpr3 dtpr4 dtpr5 mr0 mr1 mr2 mr3 mr4 mr5 mr6),
            },

        ]
        @registers = @groups.map{|g| g[:regs]}.flatten
    end
end
