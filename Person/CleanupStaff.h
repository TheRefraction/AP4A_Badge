#ifndef __CLEANUPSTAFF_H
#define __CLEANUPSTAFF_H

#include "Person.h"

class CleanupStaff : public Person {
public:
    badge::CLEARANCE_LEVEL getType() const override;
};


#endif