#ifndef __DOCTOR_H
#define __DOCTOR_H

#include "Person.h"

class Doctor : public Person {
public:
    badge::CLEARANCE_LEVEL getType() const override;
};

#endif
