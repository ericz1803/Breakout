cmake_minimum_required(VERSION 3.13.0)
project(breakout)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(breakout_VERSION_MAJOR 0)
set(breakout_VERSION_MINOR 1)

add_subdirectory(src)
add_subdirectory(test)