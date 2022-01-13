require 'yaml'

class Config

    attr_reader :groups, :registers

    def initialize()
        @groups = YAML::load_file(__dir__ + "/ddr_config.yaml")
        @registers = @groups.map{|g| g[:regs]}.flatten
    end
end
