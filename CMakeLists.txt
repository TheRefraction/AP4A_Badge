cmake_minimum_required(VERSION 4.0)
project(AP4A_Projet)

set(CMAKE_CXX_STANDARD 17)

add_executable(AP4A_Projet main.cpp
        Server.cpp
        Server.h
        old/Badge_old.cpp
        old/Badge_old.h
        old/Reader.cpp
        old/Reader.h
        Scheduler.cpp
        Scheduler.h
        Person/IPerson.h
        Person/Student.cpp
        Person/Student.h
        Badge/IBadge.h
        const.h
        Badge/StudentBadge.cpp
        Badge/StudentBadge.h
        Reader/IReader.h
        Badge/Badge.cpp
        Badge/Badge.h
        Reader/BuildingReader.cpp
        Reader/BuildingReader.h
        Reader/RoomReader.cpp
        Reader/RoomReader.h
)
add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -pedantic-errors)
