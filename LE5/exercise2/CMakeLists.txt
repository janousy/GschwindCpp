cmake_minimum_required(VERSION 3.17)
project(exercise2)

set(CMAKE_CXX_STANDARD 14)

add_executable(exercise2 main.cpp myPlayfield.h agents/human.h agents/computer1.cpp agents/computer1.h agents/com_wrapper.h agents/player.h factory.cpp factory.h playfield.h agents/computer2.h helper.h agents/computer3.h agents/computer4.h agents/computer5.h)