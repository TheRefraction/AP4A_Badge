#ifndef __IBADGE_H
#define __IBADGE_H

#include <set>
#include <memory>

#include "../Person/IPerson.h"
#include "../Time/TimeSlot.h"

class IBadge {
public:
    virtual unsigned int getId() const = 0;
    virtual std::shared_ptr<IPerson> getOwner() const = 0;
    virtual std::chrono::system_clock::time_point getDate() const = 0;
    virtual std::set<unsigned int> getPermissions() const = 0;

    virtual bool hasPermission(unsigned int perm) const = 0;
    virtual void addPermission(unsigned int perm) = 0;
    virtual void removePermission(unsigned int perm) = 0;
    virtual void clearPermissions() = 0;

    virtual void setDate(std::chrono::system_clock::time_point d) = 0;

    virtual ~IBadge() = default;
};

#endif