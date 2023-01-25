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
