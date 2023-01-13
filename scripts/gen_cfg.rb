#!/bin/env ruby

require 'optparse'
require 'erb'
require 'logger'
require 'pp'

require_relative 'config_registers.rb'
require_relative 'soc/chip.rb'
require_relative 'ddr/ddr_process.rb'
require_relative 'ddr/ddr3.rb'

def calc_value(reg, settings)
    val = 0
    reg[:fields].each do|f|
        fname = f[:name]
        fval = f[:default]
        if settings.has_key?(fname)
            fval = settings[fname]
        end
        val += (fval << f[:pos])
    end
    return sprintf("0x%08x", val)
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

def convert_hex(regs, settings)
    values = Hash.new
    regs.each do|r, f|
        values[r] = calc_value(f, settings[r])
    end
    return values
end

# Parse options
$option = {
    :platform	=> "sparx5",
    :memory	=> "ddr3_ref",
    :debug	=> false,
    :verbose	=> false,
    :format	=> "devicetree",
}

$l = Logger.new(STDERR)
$l.level = Logger::WARN

OptionParser.new do |opts|
    opts.banner = "Usage: cfg_gen.rb [options]"
    opts.version = 0.1
    opts.on("-p", "--platform <platform>", "Generate for given platform") do |p|
        $option[:platform] = p
    end
    opts.on("-m", "--memory <memory>", "Generate for given memory parameters set") do |m|
        $option[:memory] = m
    end
    opts.on("-d", "--debug", "Enable debug messages") do
        $option[:debug] = true
        $l.level = Logger::DEBUG
    end
    opts.on("-v", "--verbose", "Enable verbose messages") do
        $option[:verbose] = true
        $l.level = Logger::INFO
    end
    opts.on("-f", "--format <format>", %w(devicetree yaml), "Use format (devicetree, yaml)") do |f|
        $option[:format] = f
    end
end.order!

# Prepare default values, registers, etc.
$config = Config.new()
$chip = Chip.new($option[:platform])

cfg_regs = get_config_regs()
reg_settings = Hash.new
cfg_regs.keys.map {|r| reg_settings[r] = Hash.new }

# Load platform/memory parameters
params = YAML::load_file(__dir__ + "/profiles/#{$option[:platform]}.yaml")
params.merge!(YAML::load_file(__dir__ + "/profiles/#{$option[:memory]}.yaml"))

params[:dq_bits_per_mem] = params[:CONFIGURED_DQ_BITS]

case params[:mem_type]
when "DDR3"
    params = ddr3(params)
when "DDR4"
    raise "Unsupported for now"
else
    raise "Unsupported memory type: #{params[:mem_type]}"
end

# Calculate derived settings
params = ddr_process(params)

# Feed the chicken and go home
hex_values = convert_hex(cfg_regs, reg_settings)
renderer = ERB.new(File.read(__dir__ + "/templates/#{$option[:format]}.erb"), nil, '-')
puts renderer.result(binding)
