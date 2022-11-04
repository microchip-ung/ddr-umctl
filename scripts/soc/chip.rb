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

class Chip

    attr_reader :chip

    def initialize(chipname)
        @chip = SoC.new("#{chipname}.yaml")
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
