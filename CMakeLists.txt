cmake_minimum_required(VERSION 2.6)
project(aegisengine)
add_definitions("-Wall -std=c++11")

file(
        GLOB_RECURSE
        source_files
        src/*
        src/component/*
        src/component/NeuronalNet.cpp
        src/test/
)

add_executable(aegisengine ${source_files})

install(TARGETS aegisengine RUNTIME DESTINATION bin)
target_link_libraries(aegisengine -lz -lsfml-network -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system)