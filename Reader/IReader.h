#ifndef __IREADER_H
#define __IREADER_H

#include <string>

#include "../Badge/IBadge.h"

class IReader {
public:
    virtual bool queryAccess(const IBadge& badge) = 0;

    virtual void enable(bool e) = 0;

    virtual std::string_view getName() const = 0;
    virtual bool isEnabled() const = 0;

    virtual ~IReader() = default;
};

#endif