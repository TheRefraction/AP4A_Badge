#ifndef __BADGE_H
#define __BADGE_H

#include <vector>

#include "IBadge.h"

class Badge : public IBadge{
        int id;
        IPerson& owner;
        time_t date;
        std::vector<int> permissions;
    public:
        Badge(int id, IPerson& o);

        int getId() const override;
        IPerson& getOwner() const override;

        time_t getDate() const override;
        std::vector<int> getPermissions() const override;

        void setDate(time_t d) override;
};


#endif