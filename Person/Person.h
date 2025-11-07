#ifndef __PERSON_H
#define __PERSON_H

#include "IPerson.h"

class Person : public IPerson {
    std::string name;
public:
    Person(std::string name);

    std::string_view getName() const override;
    badge::CLEARANCE_LEVEL getType() const override;
};


#endif