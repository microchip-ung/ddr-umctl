cmake_minimum_required(VERSION 3.10)

# set the project name
project(ddr_umctl)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSTANDALONE -Wall")

# add the executable
add_executable(sparx5_ddr_umctl src/main.c src/pcb135_config.c src/pcb134_config.c src/sparx5_reset.c src/ddr_umctl.c)

target_include_directories(sparx5_ddr_umctl PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/include"
  "${PROJECT_SOURCE_DIR}/include/sparx5"
  )

add_dependencies(sparx5_ddr_umctl gen_configs)

add_custom_command(
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/configs/profiles/lan966x.yaml
  OUTPUT
  ${CMAKE_CURRENT_SOURCE_DIR}/output/maserati.yaml
  COMMAND
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb -p lan966x -m lan966x -f yaml > ${CMAKE_CURRENT_SOURCE_DIR}/output/maserati.yaml
  )

add_custom_command(
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/configs/profiles/lan969x.yaml
  OUTPUT
  ${CMAKE_CURRENT_SOURCE_DIR}/output/laguna.yaml
  COMMAND
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb -p lan966x -m lan969x -f yaml > ${CMAKE_CURRENT_SOURCE_DIR}/output/laguna.yaml
  )

add_custom_command(
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/configs/profiles/pcb134_ddr4.yaml
  OUTPUT
  ${CMAKE_CURRENT_SOURCE_DIR}/output/pcb134_ddr4.yaml
  COMMAND
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb -p sparx5  -m pcb134_ddr4 -f yaml > ${CMAKE_CURRENT_SOURCE_DIR}/output/pcb134_ddr4.yaml
  )

add_custom_command(
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/configs/profiles/pcb134_ddr4_16bit.yaml
  OUTPUT
  ${CMAKE_CURRENT_SOURCE_DIR}/output/pcb134_ddr4_16bit.yaml
  COMMAND
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb -p sparx5  -m pcb134_ddr4_16bit -f yaml > ${CMAKE_CURRENT_SOURCE_DIR}/output/pcb134_ddr4_16_bit.yaml
  )

add_custom_command(
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/configs/profiles/pcb134_ddr4.yaml
  OUTPUT
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pcb134_config.c
  COMMAND
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb -p sparx5  -m pcb134_ddr4 -f source > ${CMAKE_CURRENT_SOURCE_DIR}/src/pcb134_config.c
  )

add_custom_command(
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/configs/profiles/pcb135_ddr3.yaml
  OUTPUT
  ${CMAKE_CURRENT_SOURCE_DIR}/output/pcb135_ddr3.yaml
  COMMAND
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb -p sparx5  -m pcb135_ddr3 -f yaml > ${CMAKE_CURRENT_SOURCE_DIR}/output/pcb135_ddr3.yaml
  )

add_custom_command(
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/configs/profiles/pcb135_ddr3.yaml
  OUTPUT
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pcb135_config.c
  COMMAND
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb -p sparx5  -m pcb135_ddr3 -f source > ${CMAKE_CURRENT_SOURCE_DIR}/src/pcb135_config.c
  )

add_custom_target(
  gen_configs ALL
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/output/maserati.yaml
  ${CMAKE_CURRENT_SOURCE_DIR}/output/laguna.yaml
  ${CMAKE_CURRENT_SOURCE_DIR}/output/pcb134_ddr4.yaml
  ${CMAKE_CURRENT_SOURCE_DIR}/output/pcb134_ddr4_16bit.yaml
  ${CMAKE_CURRENT_SOURCE_DIR}/output/pcb135_ddr3.yaml
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pcb134_config.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pcb135_config.c
)
