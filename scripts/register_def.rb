require 'erb'
require 'pp'
require_relative 'soc/chip.rb'
require_relative 'config_registers.rb'

config = Config.new()
soc = Chip.new("sparx5")

renderer = ERB.new(File.read(__dir__ + "/templates/register_def.erb"), nil, '-')
puts renderer.result(binding)
