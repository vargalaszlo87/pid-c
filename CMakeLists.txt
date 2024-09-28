cmake_minimum_required(VERSION 3.27)
project(pid_c C)

set(CMAKE_C_STANDARD 99)

add_executable(pid_c
        include/pidc.h
        src/pidc.c
        tests/test_pidc.c)
