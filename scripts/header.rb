require 'erb'
require 'pp'
require_relative 'config_registers.rb'

config = Config.new()
renderer = ERB.new(File.read(__dir__ + "/templates/header.erb"), nil, '-')
puts renderer.result(binding)

