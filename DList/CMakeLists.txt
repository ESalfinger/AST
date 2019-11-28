cmake_minimum_required(VERSION 3.15)
project(DList)

set(CMAKE_CXX_STANDARD 14)

add_executable(DList main.cpp DList.cpp headers/DList.h Node.cpp headers/Node.h headers/IFIterator.h DListIterator.cpp headers/DListIterator.h PointerKey.cpp headers/PointerKey.h headers/IKey.h)