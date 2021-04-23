cmake_minimum_required(VERSION 3.17)
project(colocviu)

set(CMAKE_CXX_STANDARD 14)

add_executable(colocviu main.cpp Masca.cpp Masca.h MascaChirurgicala.cpp
        MascaChirurgicala.h MascaPolicarbonat.cpp MascaPolicarbonat.h Dezinfectant.cpp Dezinfectant.h
        DezinfectantBacterii.cpp DezinfectantBacterii.h DezinfectantVirusuri.cpp DezinfectantVirusuri.h DezinfectantFungi.cpp DezinfectantFungi.h)