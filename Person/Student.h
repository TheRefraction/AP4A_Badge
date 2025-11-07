#ifndef __STUDENT_H
#define __STUDENT_H

#include "IPerson.h"

class Student : public IPerson {
    std::string name;
public:
    Student(std::string name);

    badge::CLEARANCE_LEVEL getType() const override;
    std::string_view getName() const override;
};

#endif