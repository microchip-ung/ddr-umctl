#!/bin/env ruby

require 'optparse'
require 'erb'
require 'logger'
require 'pp'

require_relative 'soc/chip.rb'

# Parse options
$option = {
    :platform	=> "lan966x",
    :memory	=> "lan966x",
    :debug	=> false,
    :verbose	=> false,
    :format	=> "source",
}

$l = Logger.new(STDERR)
$l.level = Logger::WARN

OptionParser.new do |opts|
    opts.banner = "Usage: fmt_cfg.rb [options] files..."
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
    opts.on("-f", "--format <format>", %w(devicetree yaml source), "Use format (devicetree, yaml, source)") do |f|
        $option[:format] = f
    end
end.order!

# Prepare default values, registers, etc.
$soc = Chip.new($option[:platform])

# Load platform/memory parameters
params = YAML::load_file(__dir__ + "/profiles/#{$option[:memory]}.yaml")

params[:version] = $option[:memory] + " " +
                   Time.now.utc.strftime("%Y-%m-%d-%H:%M:%S") + " " +
                   %x( git describe --always --dirty --tags ).chop

while ARGV.length > 0
    hex_values = Hash.new
    YAML::load_file(ARGV.shift).each do|k,v|
        hex_values[k.upcase] = sprintf("0x%08x", v)
    end

    renderer = ERB.new(File.read(__dir__ + "/templates/#{$option[:format]}.erb"), nil, '-')
    puts renderer.result(binding)
end
