cmake_minimum_required(VERSION 3.15)
project(Enigma)

set(CMAKE_CXX_STANDARD 14)

add_executable(Enigma main.cpp headers/Enigma.h headers/EncoderModule.h headers/Rotor.h headers/Reflector.h Enigma.cpp Rotor.cpp EncoderModule.cpp Reflector.cpp)