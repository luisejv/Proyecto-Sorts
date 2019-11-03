cmake_minimum_required(VERSION 3.15)
project(Proyecto_2_Final)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto_2_Final main.cpp container.hpp
        sumarizar.h map.hpp deserializador.hpp
        Sorter.hpp Quick.hpp Merge.hpp Heap.hpp Shell.hpp
        funciones.hpp)