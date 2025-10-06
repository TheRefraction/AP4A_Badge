cmake_minimum_required(VERSION 4.0)
project(AP4A_Projet)

set(CMAKE_CXX_STANDARD 17)

add_executable(AP4A_Projet main.cpp
        Server.cpp
        Server.h
        Badge.cpp
        Badge.h
        Reader.cpp
        Reader.h
        Scheduler.cpp
        Scheduler.h
        Person.cpp
        Person.h
        const.h)
add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -pedantic-errors)
