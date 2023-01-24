require 'optparse'
require 'erb'
require 'pp'
require_relative 'soc/chip.rb'

$option = { :platform   => "lan966x", };

OptionParser.new do |opts|
    opts.banner = "Usage: script [options]"
    opts.version = 0.1
    opts.on("-p", "--platform <platform>", "Use given platform") do |p|
        $option[:platform] = p
    end
end.order!

soc = Chip.new($option[:platform])

renderer = ERB.new(File.read(__dir__ + "/templates/register_def.erb"), nil, '-')
puts renderer.result(binding)
