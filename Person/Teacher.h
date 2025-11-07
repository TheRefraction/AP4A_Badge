#ifndef __TEACHER_H
#define __TEACHER_H

#include "Person.h"

class Teacher : public Person {
public:
    Teacher(std::string name) : Person(std::move(name)) {}
    badge::CLEARANCE_LEVEL getType() const override {return badge::CLEARANCE_LEVEL::TEACHER;}
};


#endif