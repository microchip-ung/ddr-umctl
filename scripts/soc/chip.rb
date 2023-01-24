require 'yaml'

class SoC

    attr_reader :targets

    def initialize(filename)
        @targets = YAML::load_file(__dir__ + "/" + filename)
    end

    def regaddr(t, g, r)
        abs = (t[:toffset] + t[:offset] + g[:offset] + r[:addr]) * 4
        return abs
    end

end

class Config

    attr_reader :groups, :registers, :chip_registers

    @@ddr4 = %w(CRCPARCTL1 DBICTL INIT6 INIT7 DRAMTMG9 DRAMTMG12
                ADDRMAP7 ADDRMAP8 DTCR0 DTCR1 SCHCR1 ZQ0PR ZQ1PR ZQ2PR ZQCR DTPR3
                DTPR4 DTPR5 MR4 MR5 MR6)

    def initialize(soc, file)
        @soc = soc
        @groups = YAML::load_file(file)
        if soc.name == "lan966x"
            @groups.each do |g|
                @@ddr4.each do |reg|
                    g[:regs].delete(reg.downcase)
                end
            end
        end
        @registers = @groups.map{|g| g[:regs]}.flatten
        @chip_registers = Hash.new
        @groups.each do|rg|
            rg[:regs].each do|r|
                a = @soc.find(r)
                if a
                    @chip_registers[r] = a[2]
                else
                    raise "Unknown reg #{r}"
                end
            end
        end
    end

    def register_value_set()
        reg_settings = Hash.new
        @chip_registers.keys.map {|r| reg_settings[r.upcase] = Hash.new }
        return reg_settings
    end

end

class Chip

    attr_reader :chip, :config, :name

    def initialize(chipname)
        @name = chipname
        @chip = SoC.new("#{chipname}.yaml")
        @config = Config.new(self, __dir__ + "/ddr_config.yaml")
    end

    def find(regname)
        regname.upcase!
        @chip.targets.each do|t|
            t[:groups].each do|g|
                g[:registers].each do|r|
                    if r[:name] == regname
                        return [t, g, r]
                    end
                end
            end
        end
        return nil
    end

    def find_by_address(addr)
        #printf("Look up: 0x%08x\n", addr)
        @chip.targets.each do|t|
            t[:groups].each do|g|
                g[:registers].each do|r|
                    raddr = @chip.regaddr(t,g,r)
                    #printf("%-24s 0x%08x\n", t[:name].upcase + "_" + r[:name], raddr)
                    if raddr == addr
                        return r
                    end
                end
            end
        end
        return nil
    end

    def reggrp(regname)
        regname.upcase!
        @chip.targets.each do|t|
            t[:groups].each do|g|
                if g[:registers].map{|r| r[:name]}.include?(regname)
                    return g[:name]
                end
            end
        end
        return nil
    end

    def target(regname)
        @chip.targets.each do|t|
            t[:groups].each do|g|
                if g[:registers].map{|r| r[:name]}.include?(regname)
                    return t[:name]
                end
            end
        end
        return nil
    end

end
