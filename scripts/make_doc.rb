#!/bin/env ruby

require 'optparse'
require 'erb'
require 'pp'
require 'fileutils'

require_relative 'soc/chip.rb'

def soc_fields(soc, rname)
    fields = soc.map{|p,s| [p, s.fields(rname)]}.to_h
end

def all_field_names(fields)
    all = fields.select{|p, flds| flds != nil }.map{|p, flds| flds.map{|f| f[:name]} }.flatten.uniq
end

def make_row(fields, fname)
    doc = Array.new
    fields.keys.each do |p|
        if fields[p]
            f = fields[p].find{|h| h[:name] == fname}
            if f
                doc << f[:doc].gsub("\n", " ")
            else
                doc << ""
            end
        else
            doc << ""
        end
    end

    str = ""
    while doc.length > 0
        if doc.length >= 3 && doc[0] == doc[1] && doc[1] == doc[2]
            str += (" 3+| " + doc[0])
            doc.shift(3)
        elsif doc.length >= 2 && doc[0] == doc[1]
            str += (" 2+| " + doc[0])
            doc.shift(2)
        else
            str += (" | " + doc.shift)
        end
    end

    return str
end

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
