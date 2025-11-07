#ifndef __DOCTOR_H
#define __DOCTOR_H

#include "Person.h"

class Doctor : public Person {
public:
    Doctor(std::string name) : Person(std::move(name)) {}
    badge::CLEARANCE_LEVEL getType() const override {return badge::CLEARANCE_LEVEL::DOCTOR;}
};

#endif
