cmake_minimum_required(VERSION 3.15)
project(ClubManager)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClubManager main.cpp headers/Member.h headers/Society.h headers/SupportingMember.h headers/ActiveMember.h headers/ChairMember.h headers/HonoraryMember.h headers/TopAthlete.h headers/AmateurAthlete.h headers/Trainer.h Member.cpp ChairMember.cpp ActiveMember.cpp Society.cpp)