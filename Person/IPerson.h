#ifndef __IPERSON_H
#define __IPERSON_H

#include <string>

#include "../const.h"

class IPerson {
public:
    virtual std::string_view getName() const = 0;
    virtual badge::CLEARANCE_LEVEL getType() const = 0;
    virtual ~IPerson() = default;
};

#endif