#ifndef __IBADGE_H
#define __IBADGE_H

#include "../Person/IPerson.h"

class IBadge {
public:
    virtual int getId() const = 0;
    virtual IPerson* getOwner() const = 0;
    virtual int getAccessType() const = 0;
    virtual ~IBadge() = default;
};

#endif