cmake_minimum_required(VERSION 3.30)
project(Programme C)

set(CMAKE_C_STANDARD 11)

add_executable(Programme main.c
        Projet.h
        Welcome.c
        nettoyage.c
        recherche.c)
