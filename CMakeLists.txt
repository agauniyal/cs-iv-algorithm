cmake_minimum_required(VERSION 2.8)
project(cs-iv-algorithm)

include_directories(src)
set(CMAKE_CXX_FLAGS "-std=c++11")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable(tests.o src/cs-iv-algorithm.cpp test/catch.hpp test/test.cpp)
