require 'yaml'

class Soc

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
        @chip = Soc.new("Sparx5.yaml")
    end

    def reggrp(regname)
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
