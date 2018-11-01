cmake_minimum_required(VERSION 3.12)
project(UTPOD_LINUX)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(UTPOD_LINUX
        song.cpp
        song.h
        UtPod.cpp
        UtPod.h
        UtPodDriver.cpp)
