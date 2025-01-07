cmake_minimum_required(VERSION 3.28)
project(vNES)

set(CMAKE_CXX_STANDARD 23)

add_executable(vNES main.cpp
        vBus.cpp
        vBus.h
        vSystemRam.cpp
        vSystemRam.h)
