#ifndef __BADGE_H
#define __BADGE_H

#include "IBadge.h"

class Badge : public IBadge{
        int id;
        IPerson& owner;
        std::chrono::system_clock::time_point date;
        TimeSlot timeSlot;
        std::set<int> permissions;
    public:
        Badge(int id, IPerson &o, const TimeSlot& ts);

        int getId() const override;
        IPerson& getOwner() const override;
        std::chrono::system_clock::time_point getDate() const override;
        TimeSlot& getAccessTimeSlot() override;
        std::set<int> getPermissions() const override;

        bool hasPermission(int perm) const override;

        void addPermission(int perm) override;
        void removePermission(int perm) override;
        void clearPermissions() override;

        void setDate(std::chrono::system_clock::time_point d) override;
};


#endif