cmake_minimum_required(VERSION 3.10)

# set the project name
project(ddr_umctl)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# add the executable
add_executable(ddr_umctl src/main.c src/ddr_umctl.c)

target_include_directories(ddr_umctl PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/include"
                          )
