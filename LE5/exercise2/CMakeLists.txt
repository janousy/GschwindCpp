cmake_minimum_required(VERSION 3.17)
project(exercise2)

set(CMAKE_CXX_STANDARD 14)

add_executable(exercise2 main.cpp playfield.h agents/human.cpp agents/human.h agents/computer.cpp agents/computer.h agents/dominique.cpp agents/com_wrapper.cpp agents/com_wrapper.h agents/player.h)