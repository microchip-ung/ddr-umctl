#!/bin/env ruby

require 'optparse'
require 'pp'
require 'erb'
require 'logger'
require_relative 'soc/chip.rb'

$l = Logger.new(STDERR)
$l.level = Logger::WARN

$option = { :platform   => "sparx5", };

OptionParser.new do |opts|
    opts.banner = "Usage: script [options]"
    opts.version = 0.1
    opts.on("-p", "--platform <platform>", "Use given platform") do |p|
        $option[:platform] = p
    end
    opts.on("-d", "--debug", "Enable debug messages") do
        $l.level = Logger::DEBUG
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
                $l.warn "Unknown reg #{r}"
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
                $l.debug "#{line} (#{r[:name]})"
                reg_use[r[:name]] = data[2]
            else
                $l.debug "Not found: #{line}"
            end
        end
    end
    reg_use
end

$soc = Chip.new($option[:platform])

log = ARGV.shift

writes = record_writes($soc, log)

cfg_regs = $soc.config.register_value_set()

reg_values = Hash.new
writes.each do |r, v|
    if cfg_regs[r]
        reg_values[r] = v.to_i(16)
    end
end

#pp hex_values

info = { 'version'   => "Extracted from #{log}",
         'speed'     => 0,
         'mem_size_mb' => 0,
         'bus_width' => $soc.bus_width,
         'platform'  => $soc.name,
       }
data = { 'info' => info, 'config' => reg_values.transform_keys(&:downcase) }
renderer = ERB.new(File.read(__dir__ + "/templates/yaml.erb"), nil, '-')
puts renderer.result(binding)
