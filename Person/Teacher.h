#ifndef __TEACHER_H
#define __TEACHER_H

#include "Person.h"

class Teacher : public Person {
public:
    badge::CLEARANCE_LEVEL getType() const override;
};


#endif