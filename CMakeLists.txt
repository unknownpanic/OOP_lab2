cmake_minimum_required(VERSION 3.29)
project(_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(ConsoleApplication/x64)

add_executable(_2
        ConsoleApplication/triangle.h
    ConsoleApplication/ConsoleApplication.cpp
    ConsoleApplication/triangle.cpp)
