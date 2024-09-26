cmake_minimum_required(VERSION 3.29)
project(c_hex C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(c_hex main.c)
