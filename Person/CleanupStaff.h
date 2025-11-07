#ifndef __CLEANUPSTAFF_H
#define __CLEANUPSTAFF_H

#include "Person.h"

class CleanupStaff : public Person {
public:
    CleanupStaff(std::string name) : Person(std::move(name)) {}
    badge::CLEARANCE_LEVEL getType() const override {return badge::CLEARANCE_LEVEL::CLEANUP;}
};


#endif