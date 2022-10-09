cmake_minimum_required(VERSION 3.23)
project(SFML)

set(CMAKE_CXX_STANDARD 14)

include_directories(shootGame/include)

add_executable(SFML
        shootGame/include/Game.h
        shootGame/include/ResourceHolder.h
        shootGame/include/TextureHolder.h
        shootGame/src/Game.cpp
        shootGame/src/ResourceHolder.cpp
        shootGame/src/TextureHolder.cpp
        shootGame/main.cpp)
