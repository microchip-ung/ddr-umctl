require 'optparse'
require 'logger'
require 'pp'
require_relative 'soc/chip.rb'

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

def record_writes(chip, tracefile)
    reg_use = Hash.new
    File.open(tracefile).each do |line|
        if data = line.match(/[WwRr]([0-9a-f]{8,10})[,=]([0-9a-f]{8})/)
            reg = data[1].downcase
            r = chip.find_by_address(reg.hex)
            if r
                reg_use[reg] = Array.new if !reg_use[reg]
                reg_use[reg] << data[2]
            else
                $l.debug "Register not found: #{reg}"
            end
        end
    end
    reg_use
end

chip = Chip.new($option[:platform])

ref = ARGV.shift
new = ARGV.shift

ref_use = record_writes(chip, ref)
new_use = record_writes(chip, new)

ref_use.keys.each do|r|
    rname = chip.find_by_address(r.hex)
    if rname
        rname = rname[:name]
    end
    if new_use[r]
        rval = ref_use[r][-1]
        nval = new_use[r][-1]
        if rval != nval
            puts "*** differing value of #{rname} (#{r}) set - #{rval} vs #{nval}"
        else
            puts "Same value of #{rname} (#{r}) set (#{rval})"
            if ref_use[r].size != new_use[r].size
                puts " - but differing writes"
                pp ref_use[r]
                pp new_use[r]
            end
        end
    else
        puts "*** New needs #{rname} (#{r}) set"
    end
end

new_use.keys.each do|r|
    rname = chip.find_by_address(r.hex)
    if rname
        rname = rname[:name]
    end
    if !ref_use[r]
        puts "*** New has #{rname} (#{r}) set"
    end
end
