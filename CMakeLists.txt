cmake_minimum_required(VERSION 3.6)
project(Lab09)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES server.c)
add_executable(Lab09 ${SOURCE_FILES})