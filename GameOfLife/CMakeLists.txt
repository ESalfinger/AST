cmake_minimum_required(VERSION 3.15)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 14)

add_executable(GameOfLife main.cpp headers/Game.h Game.cpp)