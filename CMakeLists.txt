cmake_minimum_required(VERSION 2.8)
project(cs-iv-algorithm)

include_directories(src)
set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(test src/cs-iv-algorithm.cpp test/catch.hpp test/test.cpp)
