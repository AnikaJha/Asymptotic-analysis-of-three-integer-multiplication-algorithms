cmake_minimum_required(VERSION 3.15)
project(Numbers)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-O2")

add_executable(Numbers number.h number.cpp
        multiplicator.h multiplicator.cpp
        main.cpp)
