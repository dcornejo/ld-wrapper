cmake_minimum_required(VERSION 3.28)
project(ld_wrapper)

set(CMAKE_CXX_STANDARD 20)

add_executable(ld_wrapper main.cpp
        dsp.cpp
        dsp.h)
target_link_libraries(ld_wrapper liquid m)

