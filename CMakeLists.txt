cmake_minimum_required(VERSION 3.19)
project(Tst C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Tst
        lab7.c
        lab7.h
        main.c)
