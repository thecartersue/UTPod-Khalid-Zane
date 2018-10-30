cmake_minimum_required(VERSION 3.12)
project(utPod)

set(CMAKE_CXX_STANDARD 14)

add_executable(utPod utPod_driver.cpp utPod.h utPod.cpp Song.h)