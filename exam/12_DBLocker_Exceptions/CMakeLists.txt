cmake_minimum_required(VERSION 3.17)
project(DBLocker_Exceptions)

set(CMAKE_CXX_STANDARD 14)

add_executable(DBLocker_Exceptions main.cpp FileLocker.h pvector.h pvector.cpp)