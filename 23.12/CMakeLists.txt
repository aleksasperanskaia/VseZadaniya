cmake_minimum_required(VERSION 3.29)
project(23.12)

set(CMAKE_CXX_STANDARD 20)

FIND_PACKAGE(Boost 1.40 COMPONENTS program_options REQUIRED)

add_executable(23.12 main.cpp)

TARGET_LINK_LIBRARIES(23.12 Boost::program_options)
