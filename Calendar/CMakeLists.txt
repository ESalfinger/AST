cmake_minimum_required(VERSION 3.15)
project(Calendar)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calendar main.cpp Calendar.cpp headers/Calendar.h Date.cpp headers/Date.h CalendarEntry.cpp headers/CalendarEntry.h)