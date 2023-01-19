#!/bin/env ruby

require 'optparse'
require 'pp'
require 'erb'
require_relative 'soc/chip.rb'
require_relative 'config_registers.rb'

$option = { :platform   => "sparx5", };

OptionParser.new do |opts|
    opts.banner = "Usage: script [options]"
    opts.version = 0.1
    opts.on("-p", "--platform <platform>", "Use given platform") do |p|
        $option[:platform] = p
    end
end.order!

def get_config_regs()
    regs = Hash.new
    $config.groups.each do|rg|
        rg[:regs].each do|r|
            a = $chip.find(r)
            if a
                regs[r] = a[2]
            else
                raise "Unknown reg #{r}"
            end
        end
    end
    return regs
end

def record_writes(chip, tracefile)
    reg_use = Hash.new
    File.open(tracefile).each do |line|
        line.chomp!
        if data = line.match(/[Ww]([0-9a-f]{8,10})[,=]([0-9a-f]{8})/)
            reg = data[1].downcase
            r = chip.find_by_address(reg.hex)
            if r
                #puts "#{line} (#{r[:name]})"
                reg_use[r[:name]] = data[2]
            else
                puts line
            end
        end
    end
    reg_use
end

$config = Config.new()
$chip = Chip.new($option[:platform])

log = ARGV.shift

writes = record_writes($chip, log)

cfg_regs = get_config_regs()
reg_settings = Hash.new
cfg_regs.keys.map {|r| reg_settings[r.upcase] = Hash.new }

#pp writes
#pp cfg_regs

hex_values = Hash.new
writes.each do |r, v|
    if cfg_regs[r]
        hex_values[r] = "0x" + v
    end
end

#pp hex_values

renderer = ERB.new(File.read(__dir__ + "/templates/yaml.erb"), nil, '-')
puts renderer.result(binding)
