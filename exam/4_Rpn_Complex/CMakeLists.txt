cmake_minimum_required(VERSION 3.17)
project(Rpn_Complex)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rpn_Complex main.cpp fraction.cpp fraction.h pvector.h rpn.h rpn.cpp pvector.cpp)