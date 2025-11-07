cmake_minimum_required(VERSION 3.16)
project(AP4A_Projet)

set(CMAKE_CXX_STANDARD 17)

add_executable(AP4A_Projet main.cpp
        Server.cpp
        Server.h
        Scheduler.cpp
        Scheduler.h
        Person/IPerson.h
        Person/Student.cpp
        Person/Student.h
        Badge/IBadge.h
        const.h
        Reader/IReader.h
        Reader/BuildingReader.cpp
        Reader/BuildingReader.h
        Reader/RoomReader.cpp
        Reader/RoomReader.h
        Badge/Badge.cpp
        Badge/Badge.h
        Time/TimeSlot.cpp
        Time/TimeSlot.h
        Time/timeLib.cpp
        Time/timeLib.h
        Person/Person.cpp
        Person/Person.h
        Person/Teacher.cpp
        Person/Teacher.h
        Person/Doctor.cpp
        Person/Doctor.h
        Person/CleanupStaff.cpp
        Person/CleanupStaff.h
        Person/Staff.cpp
        Person/Staff.h
)
add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -pedantic-errors)
