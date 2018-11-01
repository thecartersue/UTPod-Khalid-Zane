cmake_minimum_required(VERSION 3.12)
project(utPod_copy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(utPod_copy
        song.cpp
        song.h
        UtPod.cpp
        UtPod.h
        UtPod_Driver.cpp)
