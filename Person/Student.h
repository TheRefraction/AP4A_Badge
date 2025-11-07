#ifndef __STUDENT_H
#define __STUDENT_H

#include "Person.h"

class Student : public Person {
public:
    Student(std::string name) : Person(std::move(name)) {}
    badge::CLEARANCE_LEVEL getType() const override {return badge::CLEARANCE_LEVEL::STUDENT;}
};

#endif