#!/bin/env ruby

require 'yaml'
require 'json'

puts "const ddr_config = ["
ARGV.each do|f|
    cfg = `./scripts/gen_cfg.rb -f yaml #{f}`
    data = YAML.load(cfg)
    printf "  %s,\n", JSON.dump(data)
end
puts "];"
