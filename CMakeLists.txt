cmake_minimum_required(VERSION 3.26)
project(algorithm)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(programmers)

add_executable(test test.cpp)
add_executable(ignored ignored/naver1.cpp
        ignored/naver2.cpp)
