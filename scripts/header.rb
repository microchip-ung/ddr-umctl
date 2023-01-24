require 'optparse'
require 'erb'
require 'pp'
require_relative 'soc/chip.rb'

# Parse options
$option = {
    :platform	=> "sparx5",
}

OptionParser.new do |opts|
    opts.banner = "Usage: #{$0} [options]"
    opts.version = 0.1
    opts.on("-p", "--platform <platform>", "Use platform") do |p|
        $option[:platform] = p
    end
end.order!

# Prepare default values, registers, etc.
$chip = Chip.new($option[:platform])

config = $chip.config
renderer = ERB.new(File.read(__dir__ + "/templates/header.erb"), nil, '-')
puts renderer.result(binding)

