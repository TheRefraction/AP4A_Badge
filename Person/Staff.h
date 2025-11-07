#ifndef __STAFF_H
#define __STAFF_H

#include "Person.h"

class Staff : public Person {
public:
    Staff(std::string name) : Person(std::move(name)) {}
    badge::CLEARANCE_LEVEL getType() const override {return badge::CLEARANCE_LEVEL::STAFF;}
};


#endif