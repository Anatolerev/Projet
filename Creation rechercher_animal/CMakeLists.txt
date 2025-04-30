cmake_minimum_required(VERSION 3.30)
project(Creation_rechercher_animal C)

set(CMAKE_C_STANDARD 11)

add_executable(Creation_rechercher_animal main.c
        test.h
        rechercher.c)
