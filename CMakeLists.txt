cmake_minimum_required(VERSION 4.1)
project(cell_field)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/headers)

add_executable(cell_field
        src/code/classes.cpp
        src/code/funcs.cpp
        src/code/main.cpp
        src/headers/classes.h
        src/headers/const.h
        src/headers/funcs.h
        src/headers/include.h)
