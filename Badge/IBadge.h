#ifndef __IBADGE_H
#define __IBADGE_H

#include <set>

#include "../Person/IPerson.h"
#include "../Time/TimeSlot.h"

class IBadge {
public:
    virtual int getId() const = 0;
    virtual IPerson& getOwner() const = 0;
    virtual std::chrono::system_clock::time_point getDate() const = 0;
    virtual TimeSlot& getAccessTimeSlot() const = 0; /// ???
    virtual std::set<int> getPermissions() const = 0;

    virtual bool hasPermission(int perm) const = 0;
    virtual void addPermission(int perm) = 0;
    virtual void removePermission(int perm) = 0;
    virtual void clearPermissions() = 0;

    virtual void setDate(std::chrono::system_clock::time_point d) = 0;

    virtual ~IBadge() = default;
};

#endif