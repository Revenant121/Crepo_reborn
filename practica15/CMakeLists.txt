cmake_minimum_required(VERSION 3.28)
project(practica15 C)

set(CMAKE_C_STANDARD 11)

add_executable(practica15 main.c
        node.c
        node.h
        student.c
        student.h)
