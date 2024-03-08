cmake_minimum_required(VERSION 3.27)
project(morpion)

set(CMAKE_CXX_STANDARD 17)
add_link_options(-static -static-libgcc -static-libstdc++)

add_executable(morpion main.cpp
        morpion/game.cpp
        morpion/game.h
        morpion/Plateau.cpp
        morpion/Plateau.h
)
