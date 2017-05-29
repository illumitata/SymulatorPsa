cmake_minimum_required(VERSION 3.6)
project(projekt_jezyki)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES symulator.c)
add_executable(projekt_jezyki ${SOURCE_FILES})