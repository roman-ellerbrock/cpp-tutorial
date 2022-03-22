cmake_minimum_required(VERSION 3.20)
project(CPP_tutorial)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPP_lecture
        lectures/cMatrix.cpp
        lectures/Matrix.cpp
        lectures/lecture.cpp
        main.cpp)

add_subdirectory(tutorial-1)