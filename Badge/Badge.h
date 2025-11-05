#ifndef __BADGE_H
#define __BADGE_H

#include "IBadge.h"

class Badge : public IBadge {
    static int nextId;
    int id;
    IPerson* owner;

public:
    Badge(IPerson* p);

    int getId() const override;
    IPerson* getOwner() const override;
};

int Badge::nextId = 1;

#endif