#ifndef __BADGE_H
#define __BADGE_H

#include "Person.h"

class Badge {
    Person& person;
public:
    Badge(Person& person);
};


#endif