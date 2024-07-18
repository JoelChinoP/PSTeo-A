cmake_minimum_required(VERSION 3.27)
project(PROYECTO)

set(CMAKE_CXX_STANDARD 14)

include_directories(Ex01)
include_directories(Ex02)
include_directories(Ex03)
include_directories(Ex04)
include_directories(Ex05)

add_executable(PROYECTO
        Exceptions.cpp
        Exceptions.h
        FileManager.cpp
        FileManager.h
        main.cpp
        Prestamo.cpp
        Prestamo.h
        Registro.h
        Registro.cpp
        Usuario.h
        Usurario.cpp

)
