#ifndef __STAFF_H
#define __STAFF_H

#include "Person.h"

class Staff : public Person {
public:
    badge::CLEARANCE_LEVEL getType() const override;
};


#endif