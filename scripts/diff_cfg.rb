#!/bin/env ruby

require 'optparse'
require 'erb'
require 'logger'
require 'pp'

require_relative 'soc/chip.rb'

# Parse options
$option = {
    :debug	=> false,
    :verbose	=> false,
}

$l = Logger.new(STDERR)
$l.level = Logger::WARN

OptionParser.new do |opts|
    opts.banner = "Usage: #{$0} [options] <CFG1> <CFG2>"
    opts.version = 0.1
    opts.on("-p", "--platform <platform>", "Use platform") do |p|
        $option[:platform] = p
    end
    opts.on("-d", "--debug", "Enable debug messages") do
        $option[:debug] = true
        $l.level = Logger::DEBUG
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

def reg_diff(r, reg1, reg2)
  a = $chip.find(r)
  if a
    rdef = a[2]
  else
    raise "Unknown reg #{r}"
  end
  rdef[:fields].each do|f|
    v1 = extract_field(f, reg1)
    v2 = extract_field(f, reg2)
    fval = f[:default]
    if v1 != v2
      printf "  %-36s: %8d %8d\t(default %d)\n", f[:name], v1, v2, f[:default]
    #elsif v1 != f[:default]
    #  printf "  %-30s: %8d %8s\t(default %d)\n", f[:name], v1, "same", f[:default]
    end
  end
end

if ARGV.length != 2
  raise "Usage: #{$0} [options] <CFG1> <CFG2>"
end

f1 = ARGV.shift
cfg1 = YAML::load_file(f1)
f2 = ARGV.shift
cfg2 = YAML::load_file(f2)

# Prepare default values, registers, etc.
platform = $option[:platform] ? $option[:platform] : cfg1['info']['platform']
$chip = Chip.new(platform)

printf("Comparing                                 %s %s\n",
       File.basename(f1, ".yaml"),
       File.basename(f2, ".yaml"))

cfg1 = cfg1['config']
cfg2 = cfg2['config']

$is_ddr4 = (cfg1["mstr"] & (1 << 4)) != 0 # BIT(4)
$chip.config.groups.each do |rg|
  puts "Group: #{rg[:name]}"
  rg[:regs].sort.each do |rname|
    rname.downcase!
    if $is_ddr4 && rname.match(/^mr/)
      prname = rname + "_ddr4"
    else
      prname = rname
    end
    printf(" %-10s: %s %s\n", rname,
           cfg1[rname] ? sprintf("%08x", cfg1[rname]) : ("--------"),
           cfg2[rname] ? sprintf("%08x", cfg2[rname]) : ("--------"))
    reg_diff(prname,
             cfg1[rname] ? cfg1[rname] : 0,
             cfg2[rname] ? cfg2[rname] : 0)
  end
end
