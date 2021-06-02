cmake_minimum_required(VERSION 3.17)
project(incercare1)

set(CMAKE_CXX_STANDARD 14)

add_executable(incercare1 main.cpp
        patiserie.cpp
        produs.cpp
        personal.cpp
        input.txt
        output.txt

        experimentat.cpp
        placinta.cpp placinta.h novice.cpp novice.h experimentat.cpp experimentat.h manager.cpp manager.h reprezentant.cpp reprezentant.h gramaj_exception.cpp gramaj_exception.h tip_exception.cpp tip_exception.h pret_exception.cpp pret_exception.h)
