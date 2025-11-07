#ifndef __IREADER_H
#define __IREADER_H

#include <string>

#include "../const.h"
#include "../Time/TimeSlot.h"

class IReader {
public:
    virtual int getId() const = 0;
    virtual std::string_view getName() const = 0;
    virtual badge::CLEARANCE_LEVEL getType() const = 0;
    virtual TimeSlot& getAccessTimeSlot() = 0;
    virtual bool isEnabled() const = 0;

    virtual void enable() = 0;
    virtual void disable() = 0;

    virtual ~IReader() = default;
};

#endif