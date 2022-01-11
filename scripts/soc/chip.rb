require_relative 'sparx5_soc.rb'

class Chip

    attr_reader :chip

    def initialize(chipname)
        sparx5 = Sparx5.new()
        @chip = sparx5
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
