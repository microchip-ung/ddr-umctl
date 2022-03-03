require 'erb'
require 'pp'
require_relative 'config_registers.rb'
require_relative 'soc/chip.rb'

def calc_value(reg, settings)
    val = 0
    reg[:fields].each do|f|
        fname = f[:name]
        fval = f[:default]
        if settings.has_key?(fname)
            fval = settings[fname]
        end
        val += (fval << f[:pos])
    end
    return sprintf("0x%08x", val)
end

def get_config_regs()
    regs = Hash.new
    $config.groups.each do|rg|
        rg[:regs].each do|r|
            a = $chip.find(r)
            if a
                regs[r] = a[2]
            else
                raise "Unknown reg #{r}"
            end
        end
    end
    return regs
end

def convert_hex(regs, settings)
    values = Hash.new
    regs.each do|r, f|
        values[r] = calc_value(f, settings[r])
    end
    return values
end

$config = Config.new()
$chip = Chip.new("sparx5")

cfg_regs = get_config_regs()
cfg_values = Hash.new
cfg_regs.keys.map {|r| cfg_values[r] = Hash.new }

cfg_values["MSTR"]["ACTIVE_RANKS"] = 47

hex_values = convert_hex(cfg_regs, cfg_values)

renderer = ERB.new(File.read(__dir__ + "/templates/devicetree.erb"), nil, '-')
puts renderer.result(binding)
