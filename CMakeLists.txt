cmake_minimum_required(VERSION 3.10)

# set the project name
project(ddr_umctl)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSTANDALONE -Wall")

# add the executable
add_executable(sparx5_ddr_umctl src/main.c src/pcb135_ddr3_config.c src/pcb134_ddr4_config.c src/sparx5_reset.c src/ddr_umctl.c)

target_include_directories(sparx5_ddr_umctl PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/include"
  "${PROJECT_SOURCE_DIR}/include/sparx5"
  )

add_dependencies(sparx5_ddr_umctl gen_configs)

set(yaml_config_targets lan966x lan969x pcb134_ddr4 pcb135_ddr3)
foreach(TRG IN LISTS yaml_config_targets)
add_custom_command(
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/ddr/ddr3.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/ddr/ddr4.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/configs/profiles/${TRG}.yaml
  OUTPUT
  ${CMAKE_CURRENT_SOURCE_DIR}/output/${TRG}.yaml
  COMMAND
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb -f yaml ${CMAKE_CURRENT_SOURCE_DIR}/configs/profiles/${TRG}.yaml > ${CMAKE_CURRENT_SOURCE_DIR}/output/${TRG}.yaml
  )
endforeach()

set(source_config_targets pcb134_ddr4 pcb135_ddr3)
foreach(TRG IN LISTS source_config_targets)
add_custom_command(
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/ddr/ddr3.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/ddr/ddr4.rb
  ${CMAKE_CURRENT_SOURCE_DIR}/configs/profiles/${TRG}.yaml
  OUTPUT
  ${CMAKE_CURRENT_SOURCE_DIR}/src/${TRG}_config.c
  COMMAND
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_cfg.rb -f source ${CMAKE_CURRENT_SOURCE_DIR}/configs/profiles/${TRG}.yaml > ${CMAKE_CURRENT_SOURCE_DIR}/src/${TRG}_config.c
  )
endforeach()

add_custom_target(
  gen_configs ALL
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/output/lan966x.yaml
  ${CMAKE_CURRENT_SOURCE_DIR}/output/lan969x.yaml
  ${CMAKE_CURRENT_SOURCE_DIR}/output/pcb134_ddr4.yaml
  ${CMAKE_CURRENT_SOURCE_DIR}/output/pcb135_ddr3.yaml
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pcb134_ddr4_config.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pcb135_ddr3_config.c
)
