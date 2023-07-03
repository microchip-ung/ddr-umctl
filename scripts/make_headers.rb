#!/bin/env ruby

require 'optparse'
require 'erb'
require 'pp'
require 'fileutils'

require_relative 'soc/chip.rb'

top = __dir__ + "/../include"

%w(lan966x lan969x sparx5).each do|p|
    STDERR.puts "Generating for #{p}"
    soc = Chip.new(p)
    %w(ddr_config ddr_reg ddr_xlist).each do|f|
        STDERR.puts "Generating file #{f}"
        renderer = ERB.new(File.read(__dir__ + "/templates/#{f}.erb"), nil, '-')
        content = renderer.result(binding)
        outfile = "#{top}/#{p}/#{f}.h"
        FileUtils.mkdir_p(File.dirname(outfile))
        File.write(outfile, content)
    end

    %w(ddr_js).each do|f|
        STDERR.puts "Generating file #{f}"
        renderer = ERB.new(File.read(__dir__ + "/templates/#{f}.erb"), nil, '-')
        content = renderer.result(binding)
        outfile = "#{top}/#{p}/#{f}.js"
        FileUtils.mkdir_p(File.dirname(outfile))
        File.write(outfile, content)
    end

    renderer = ERB.new(File.read(__dir__ + "/templates/ddr_reg.erb"), nil, '-')
    outfile = top + "/" + p + "/ddr_reg.h"
    STDERR.puts "Generating file #{outfile}"
    ddr_reg = renderer.result(binding)
    File.write(outfile, ddr_reg)
end
