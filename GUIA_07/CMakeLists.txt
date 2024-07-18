cmake_minimum_required(VERSION 3.27)
project(GUIA_07)

set(CMAKE_CXX_STANDARD 14)

include_directories(Ex01)
include_directories(Ex02)
include_directories(Ex03)
include_directories(Ex04)
include_directories(Ex05)

add_executable(GUIA_07
        #Ex01/main.cpp
        #Ex02/main.cpp
        #Ex03/main_01.cpp
        #Ex03/main_02.cpp
        #Ex04/main.cpp
        Ex05/ComputerException.h
        Ex05/InputException.h
        Ex05/main.cpp
        Ex05/OutputException.h
        Ex05/ProcessorException.h
)
