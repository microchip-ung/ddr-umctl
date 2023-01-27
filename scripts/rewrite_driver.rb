#!/bin/env ruby

require 'optparse'
require 'erb'
require 'logger'
require 'pp'

require_relative 'soc/chip.rb'

class RegWrite
    attr_reader :target, :name

    def initialize(target, name)
        @target = target
        @name = name
        @fields = Hash.new
    end

    def setfield(field, value)
        @fields[field] = value
    end

    def to_s(indent)
        args = @fields.values.uniq
        if args.size == 1 && (args[0] == "0" || args[0] == "0x0")
            op = "clrbits"
        elsif args.size == 1 && (args[0] == "1" || args[0] == "0x1")
            op = "setbits"
        else
            op = "clrsetbits"
        end
        line = indent + "mmio_#{op}_32(#{@name}(#{@target}),\n		"
        line += @fields.keys.map{|t| "#{@name}_#{t}_M" }.join(" |\n		");
        if op == "clrsetbits"
            line += ",\n		"
            line += @fields.map{|n, v| "#{@name}_#{n}(#{v})" }.join(" |\n		");
        end
        line += ");"
        return line
    end
end

# Parse options
$option = {
    :platform	=> "lan966x",
    :debug	=> false,
    :verbose	=> false,
}

$l = Logger.new(STDERR)
$l.level = Logger::WARN

OptionParser.new do |opts|
    opts.banner = "Usage: cfg_gen.rb [options]"
    opts.version = 0.1
    opts.on("-p", "--platform <platform>", "Generate for given platform") do |p|
        $option[:platform] = p
    end
    opts.on("-d", "--debug", "Enable debug messages") do
        $option[:debug] = true
        $l.level = Logger::DEBUG
    end
    opts.on("-v", "--verbose", "Enable verbose messages") do
        $option[:verbose] = true
        $l.level = Logger::INFO
    end
end.order!

def make_full_name(target, reg)
    return target + "_" + reg
end

def get_target(reg)
    if reg.match("DDR_UMCTL2")
        return "LAN966X_DDR_UMCTL2_BASE"
    elsif reg.match("DDR_PHY")
        return "LAN966X_DDR_PHY_BASE"
    elsif reg.match("CPU")
        return "LAN966X_CPU_BASE"
    elsif reg.match("CHIP_TOP")
        return "LAN966X_CHIP_TOP_BASE"
    end
    raise "Unknown register: #{reg}"
end

def process_file(soc, file)
    settings = soc.config.register_value_set()
    reg_defined = soc.config.chip_registers
    reg_names = Hash.new
    soc.config.groups.each do |rg|
        rg[:regs].each do |r|
            reg_names[r] = rg[:name]
        end
    end
    cur_reg = nil
    indent = ""
    stack = Hash.new
    File.open(file).each do |line|
        line.chomp!
        if data = line.match(/var = wr_fld_r_s\((.+)\);/)
            elm = data[1].split(/,/).map{|e| e.strip}
            target = elm[0]
            regname = elm[2]
            fldname = elm[3]
            if reg_names[regname]
                $l.debug "Got '#{regname}'.'#{fldname}' being read+set"
                $l.debug "Gobble: " + line
                raise "Already working on #{cur_reg}" if cur_reg
                cur_reg = regname
                indent = line.scan(/^(\s+)/).flatten[0]
                line = nil
            else
                value = elm[4]
                fullreg = make_full_name(target, regname)
                target = get_target(fullreg)
                line = nil
                raise "Active reg #{fullreg}" if stack[fullreg] != nil
                stack[fullreg] = RegWrite.new(target, fullreg)
                stack[fullreg].setfield(fldname, value)
            end
        elsif cur_reg && data = line.match(/wr_fld_s_s\((.+)\);/)
            elm = data[1].split(/,/).map{|e| e.strip}
            regname = elm[3]
            raise "#{regname}: Already working on #{cur_reg}" if cur_reg != regname
            $l.debug "Gobble: " + line
            line = nil
        elsif cur_reg && data = line.match(/wr_fld_s_r\((.+)\);/)
            elm = data[1].split(/,/).map{|e| e.strip}
            target = elm[1]
            regname = elm[3]
            fldname = elm[4]
            if reg_names[regname]
                $l.debug "Got '#{regname}'.'#{fldname}' being written"
                fullreg = make_full_name(target, regname)
                target = get_target(fullreg)
                line = indent + "mmio_write_32(#{fullreg}(#{target}), cfg->#{reg_names[regname]}.#{regname.downcase});"
                cur_reg = nil
            else
                raise "#{regname}: Working on #{cur_reg}, but not found?"
            end
        elsif data = line.match(/var = wr_fld_s_s\((.+)\);/)
            elm = data[1].split(/,/).map{|e| e.strip}
            target = elm[1]
            regname = elm[3]
            fldname = elm[4]
            value = elm[5]
            fullreg = make_full_name(target, regname)
            target = get_target(fullreg)
            raise "Mismatch #{fullreg} vs #{stack[fullreg].name}" if fullreg != stack[fullreg].name
            stack[fullreg].setfield(fldname, value)
            line = nil
        elsif data = line.match(/wr_fld_s_r\((.+)\);/)
            elm = data[1].split(/,/).map{|e| e.strip}
            target = elm[1]
            regname = elm[3]
            fldname = elm[4]
            value = elm[5]
            fullreg = make_full_name(target, regname)
            target = get_target(fullreg)
            indent = line.scan(/^(\s+)/).flatten[0]
            raise "Mismatch #{target} vs #{stack[fullreg].target}" if target != stack[fullreg].target
            raise "Mismatch #{fullreg} vs #{stack[fullreg].name}" if fullreg != stack[fullreg].name
            stack[fullreg].setfield(fldname, value)
            line = stack[fullreg].to_s(indent)
            stack[fullreg] = nil
        elsif data = line.match(/rd_reg\s*\((.+)\)/)
            elm = data[1].split(/,/).map{|e| e.strip}
            target = elm[0]
            regname = elm[2]
            fullreg = make_full_name(target, regname)
            target = get_target(fullreg)
            rep = "mmio_read_32(#{fullreg}(#{target}))"
            line[data.begin(0)..(data.end(0)-1)] = rep
        elsif data = line.match(/wr_reg\s*\((.+)\)/)
            elm = data[1].split(/,/).map{|e| e.strip}
            target = elm[0]
            regname = elm[2]
            value = elm[3]
            fullreg = make_full_name(target, regname)
            target = get_target(fullreg)
            rep = "mmio_write_32(#{fullreg}(#{target}), #{value})"
            line[data.begin(0)..(data.end(0)-1)] = rep
        elsif data = line.match(/wr_fld_r_r\s*\((.+)\);/)
            elm = data[1].split(/,/).map{|e| e.strip}
            target = elm[0]
            regname = elm[2]
            fldname = elm[3]
            value = elm[4]
            fullreg = make_full_name(target, regname)
            target = get_target(fullreg)
            indent = line.scan(/^(\s+)/).flatten[0]
            fldname = "#{fullreg}_#{fldname}"
            line = indent + "mmio_clrsetbits_32(#{fullreg}(#{target}), #{fldname}_M, #{fldname}(#{value}));"
        elsif data = line.match(/rd_fld_r\((.+)\)/)
            elm = data[1].split(/,/).map{|e| e.strip}
            target = elm[0]
            regname = elm[2]
            fldname = elm[3]
            fullreg = make_full_name(target, regname)
            target = get_target(fullreg)
            rep = "#{fullreg}_#{fldname}_X(mmio_read_32(#{fullreg}(#{target})))"
            line[data.begin(0)..(data.end(0)-1)] = rep
        end
        puts line unless line == nil
    end
end

# Prepare default values, registers, etc.
$soc = Chip.new($option[:platform])

source = ARGV.shift

writes = process_file($soc, source)
