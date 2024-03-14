cmake_minimum_required(VERSION 3.27)
project(intento)

set(CMAKE_CXX_STANDARD 17)

add_executable(intento main.cpp
        Character/Character.cpp
        Character/Character.h
        Player/Player.cpp
        Player/Player.h
        Enemy/Enemy.cpp
        Enemy/Enemy.h
        Combat/Combat.cpp
        Combat/Combat.h
        Utils.h
        Combat/Action.h
        Player/Player.cpp
        Player/Player.cpp)
