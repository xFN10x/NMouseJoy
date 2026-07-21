cmake_minimum_required(VERSION 4.3)
project(NMouseJoy)

set(CMAKE_CXX_STANDARD 26)

include_directories(libs)

add_executable(NMouseJoy NMJ.cpp)
