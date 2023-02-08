#!/bin/env ruby

require 'optparse'
require 'erb'
require 'logger'
require 'pp'

require_relative 'soc/chip.rb'

# Parse options
$option = {
    :platform	=> "lan966x",
    :debug	=> false,
    :verbose	=> false,
}

$l = Logger.new(STDERR)
$l.level = Logger::WARN

OptionParser.new do |opts|
    opts.banner = "Usage: reg_show.rb [options] files..."
    opts.version = 0.1
    opts.on("-p", "--platform <platform>", "Generate for given platform") do |p|
        $option[:platform] = p
    end
    opts.on("-d", "--debug", "Enable debug messages") do
        $option[:debug] = true
        $l.level = Logger::DEBUG
    end
    opts.on("-z", "--zero", "Omit zero fields") do
        $option[:zero] = true
    end
    opts.on("-v", "--verbose", "Enable verbose messages") do
        $option[:verbose] = true
        $l.level = Logger::INFO
    end
end.order!

def extract_field(f, val)
    v = (val >> f[:pos]) & ((1 << f[:width]) - 1)
    return v
end

def show_reg(soc, reg, value)
    a = soc.find(reg)
    if a
        t = a[0]
        grp = a[1]
        rdef = a[2]
    else
        raise "No #{reg} register found"
    end
    # printf "%s: 0x%08x\n", reg, value
    keys = Hash.new
    rdef[:fields].each do|f|
        v = extract_field(f, value)
        if (!$option[:zero] && v == 0) || v != 0
            #sym = "#{t[:name]}_#{reg}_#{f[:name]}"
            #printf "%s(%d)\n", sym, v
            keys[f[:name]] = v
        end
    end
    return keys
end

# Prepare default values, registers, etc.
$soc = Chip.new($option[:platform])

regs = Hash.new
if ARGV.length == 1 && File.exists?(ARGV[0])
    file = ARGV.shift
    data = YAML::load_file(file)
    data.each do |reg, value|
        regs[reg] = show_reg($soc, reg.upcase, value)
    end
else
    while ARGV.length > 0
        reg = ARGV.shift
        if ARGV.length
            value = ARGV.shift
            if value.match(/^0x/)
                value = value.to_i(16)
            else
                value = value.to_i
            end
        end
        regs[reg] = show_reg($soc, reg.upcase, value)
    end
end
puts regs.to_yaml()
