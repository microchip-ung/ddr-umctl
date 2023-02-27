#!/bin/env ruby

require 'optparse'
require 'erb'
require 'pp'
require 'fileutils'

require_relative 'soc/chip.rb'

soc = Hash.new
cfg = Hash.new
%w(lan966x lan969x sparx5).each do|p|
    STDERR.puts "Generating for #{p}"
    soc[p] = Chip.new(p)
    cfg[p] = soc[p].config.register_value_set()
end

conf_regs = []
cfg.each do |p, k|
    conf_regs |= k.keys
end

renderer = ERB.new(File.read(__dir__ + "/templates/reg_doc.erb"), nil, '-')
outfile = "doc/registers.adoc"
STDERR.puts "Generating file #{outfile}"
ddr_reg = renderer.result(binding)
File.write(outfile, ddr_reg)
