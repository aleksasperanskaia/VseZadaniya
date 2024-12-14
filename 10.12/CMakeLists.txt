cmake_minimum_required(VERSION 3.29)
project(10.12)

set(CMAKE_CXX_STANDARD 20)

add_executable(tests test.cpp calc.cpp)
add_executable(main main.cpp calc.cpp )
