cmake_minimum_required(VERSION 2.8)
project(cs-iv-algorithm)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

include_directories(include)
set(SOURCES ${CMAKE_SOURCE_DIR}/src/cs-iv-algorithm.cpp)

message("CMAKE_SOURCE_DIR is" ${CMAKE_SOURCE_DIR})
message("SOURCES POINT TO" ${SOURCES})

add_subdirectory(src)
add_subdirectory(tests)
