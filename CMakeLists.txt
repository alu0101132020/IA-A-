cmake_minimum_required(VERSION 3.15)
project(IA_A_)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(IA_A_
        include/Arbol.hpp
        include/grafo.hpp
        include/nodo.hpp
        src/Arbol.cpp
        src/grafo.cpp
        src/main.cpp
        src/nodo.cpp)
