require 'optparse'
require 'pp'
require_relative '../soc/chip.rb'

$option = { :platform   => "lan966x", };

OptionParser.new do |opts|
    opts.banner = "Usage: script [options]"
    opts.version = 0.1
    opts.on("-p", "--platform <platform>", "Use given platform") do |p|
        $option[:platform] = p
    end
end.order!

def record_writes(chip, config, tracefile)
    reg_use = Hash.new
    File.open(tracefile).each do |line|
        line.chomp!
        if data = line.match(/[WwRr]([0-9a-f]{8,10})[,=]([0-9a-f]{8})/)
            reg = data[1].downcase
            r = chip.find_by_address(reg.hex)
            if r
                t = chip.target(r[:name])
                if config[r[:name]]
                    puts "#{line} (Config: #{r[:name]})"
                else
                    puts "#{line} (#{t}_#{r[:name]})"
                end
            else
                puts line
            end
        else
            puts line
        end
    end
end

chip = Chip.new($option[:platform])

log = ARGV.shift

config = chip.config.register_value_set()

record_writes(chip, config, log)
