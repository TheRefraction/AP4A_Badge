cmake_minimum_required(VERSION 3.16)
project(AP4A_Projet)

set(CMAKE_CXX_STANDARD 17)

add_executable(AP4A_Projet main.cpp
        const.h
        Server/Server.cpp
        Server/Server.h
        Server/Scheduler.cpp
        Server/Scheduler.h
        Person/IPerson.h
        Person/Student.h
        Badge/IBadge.h
        Reader/IReader.h
        Reader/RoomReader.h
        Badge/Badge.cpp
        Badge/Badge.h
        Time/TimeSlot.cpp
        Time/TimeSlot.h
        Time/timeLib.cpp
        Time/timeLib.h
        Person/Person.cpp
        Person/Person.h
        Person/Teacher.h
        Person/Doctor.h
        Person/CleanupStaff.h
        Person/Staff.h
        Reader/Reader.cpp
        Reader/Reader.h
        Reader/LabReader.h
        Reader/CleanupReader.h
        Reader/TeacherReader.h
        Reader/StaffReader.h
)
add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -pedantic-errors)
