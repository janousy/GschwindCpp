cmake_minimum_required(VERSION 3.17)
project(pVector_Persistent)

set(CMAKE_CXX_STANDARD 14)

add_executable(pVector_Persistent main.cpp pvector.cpp pvector.h persistence_traits.cpp persistence_traits.h pset.cpp pset.h pvector.h)