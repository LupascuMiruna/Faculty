cmake_minimum_required(VERSION 3.17)
project(incercare1)

set(CMAKE_CXX_STANDARD 14)

add_executable(incercare1 main.cpp
        patiserie.cpp
        produs.cpp
        personal.cpp
        input.txt
        output.txt
        )
