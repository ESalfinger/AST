cmake_minimum_required(VERSION 3.15)
project(DList)

set(CMAKE_CXX_STANDARD 14)

add_executable(DList main.cpp headers/GDList.h headers/Node.h headers/DataKey.h)