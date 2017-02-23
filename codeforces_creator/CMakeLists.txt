cmake_minimum_required(VERSION 2.8)

project (codeforces)

set(CMAKE_VERBOSE_MAKEFILE on)


set(SOURCE
    740b.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

add_executable(codeforces ${SOURCE})

