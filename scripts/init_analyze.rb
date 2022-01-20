require 'pp'
require_relative 'soc/chip.rb'
require_relative 'config_registers.rb'

def record_writes(chip, tracefile)
    reg_use = Hash.new
    File.open(tracefile).each do |line|
        if data = line.match(/[Ww]([0-9a-f]{8,10})[,=]([0-9a-f]{8}) \((CPU_REGS|UMCTL2_REGS|DWC_DDRPHY_PUB|UMCTL2_MP)_(\w+)\)/)
            reg = data[4]
            reg.gsub!(/^(MR\d)_.+/, '\1')
            a = chip.find(reg)
            if a
                reg_use[reg] = Array.new if !reg_use[reg]
                reg_use[reg] << data[2]
            else
                puts "Register not found: #{reg}"
                pp data
                exit
            end
        end
    end
    reg_use
end

chip = Chip.new("sparx5")
#config = Config.new()

ref = ARGV.shift
new = ARGV.shift

ref_use = record_writes(chip, ref)
new_use = record_writes(chip, new)

ref_use.keys.each do|r|
    if new_use[r]
        rval = ref_use[r].pop
        nval = new_use[r].pop
        if rval != nval
            puts "*** differing value of #{r} set - #{rval} vs #{nval}"
        else
            puts "Same value of #{r} set (#{rval})"
        end
    else
        puts "*** New needs #{r} set"
    end
end

new_use.keys.each do|r|
    if !ref_use[r]
        puts "*** New has #{r} set"
    end
end
