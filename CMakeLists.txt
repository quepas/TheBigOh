cmake_minimum_required (VERSION 2.8)
project (TheBigOh_Main)

add_definitions("-std=c++11 -std=gnu++11")

add_subdirectory (lib)
add_subdirectory (unit_test)
add_subdirectory (examples)