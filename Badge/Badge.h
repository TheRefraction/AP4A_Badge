#ifndef __BADGE_H
#define __BADGE_H

#include "IBadge.h"

class Badge : public IBadge{
    unsigned int id;
    std::shared_ptr<IPerson> owner;
    std::chrono::system_clock::time_point date;
    std::set<unsigned int> permissions;
public:
    Badge(unsigned int id, std::shared_ptr<IPerson> o);

    unsigned int getId() const override;
    std::shared_ptr<IPerson> getOwner() const override;
    std::chrono::system_clock::time_point getDate() const override;
    std::set<unsigned int> getPermissions() const override;

    bool hasPermission(unsigned int perm) const override;

    void addPermission(unsigned int perm) override;
    void removePermission(unsigned int perm) override;
    void clearPermissions() override;

    void setDate(std::chrono::system_clock::time_point d) override;
};


#endif