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
    :format	=> "source",
}

$l = Logger.new(STDERR)
$l.level = Logger::WARN

OptionParser.new do |opts|
    opts.banner = "Usage: fmt_cfg.rb [options] files..."
    opts.version = 0.1
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

while ARGV.length > 0
    # Load platform/memory parameters
    data = YAML::load_file(ARGV.shift)
    # Prepare default values, registers, etc.
    $soc = Chip.new(data["info"]["platform"])
    renderer = ERB.new(File.read(__dir__ + "/templates/#{$option[:format]}.erb"), nil, '-')
    puts renderer.result(binding)
end
