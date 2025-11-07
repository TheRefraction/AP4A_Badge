#ifndef __IBADGE_H
#define __IBADGE_H

#include "Badge.h"
#include "Badge.h"
#include "../Person/IPerson.h"

class IBadge {
public:
    virtual int getId() const = 0;
    virtual IPerson& getOwner() const = 0;
    virtual time_t getDate() const = 0;
    virtual std::vector<int> getPermissions() const = 0;

    virtual void setDate(time_t d) = 0;

    virtual ~IBadge() = default;
};

#endif