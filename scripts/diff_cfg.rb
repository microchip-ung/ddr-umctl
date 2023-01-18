#!/bin/env ruby

require 'optparse'
require 'erb'
require 'logger'
require 'pp'

require_relative 'config_registers.rb'
require_relative 'soc/chip.rb'

# Parse options
$option = {
    :platform	=> "sparx5",
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

# Prepare default values, registers, etc.
$config = Config.new()
$chip = Chip.new($option[:platform])

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

cfg_regs = get_config_regs()

if ARGV.length != 2
  raise "Usage: #{$0} [options] <CFG1> <CFG2>"
end

f1 = ARGV.shift
cfg1 = YAML::load_file(f1)
f2 = ARGV.shift
cfg2 = YAML::load_file(f2)

printf("Comparing                                 %s %s\n",
       File.basename(f1, ".yaml"),
       File.basename(f2, ".yaml"))

$config.groups.each do |rg|
  puts "Group: #{rg[:name]}"
  rg[:regs].sort.each do |rname|
    rname.downcase!
    if cfg1[rname] && cfg2[rname]
      printf(" %-10s: %08x %08x\n", rname, cfg1[rname], cfg2[rname])
      reg_diff(rname, cfg1[rname], cfg2[rname])
    else
      printf(" %-10s: %s %s\n", rname,
             cfg1[rname] ? sprintf("%08x", cfg1[rname]) : ("--------"),
             cfg2[rname] ? sprintf("%08x", cfg2[rname]) : ("--------"))
    end
  end
end
