cmake_minimum_required(VERSION 3.3)
project(ReverseList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test.cpp list.hpp)
add_executable(ReverseList ${SOURCE_FILES})