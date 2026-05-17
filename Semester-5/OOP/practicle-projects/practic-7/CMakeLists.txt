cmake_minimum_required(VERSION 4.3)
project(practic_7)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(practic_7 clases/main.cpp
        clases/Object.cpp
        clases/Object.h
        clases/Sphere.cpp
        clases/Sphere.h
        clases/Pyramid.cpp
        clases/Pyramid.h
        clases/TriangularPyramid.cpp
        clases/TriangularPyramid.h
        clases/QuadrangularPyramid.cpp
        clases/QuadrangularPyramid.h
        clases/Menu.h
        clases/Menu.cpp
)
