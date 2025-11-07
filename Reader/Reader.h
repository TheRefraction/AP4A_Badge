#ifndef __READER_H
#define __READER_H

#include "IReader.h"

class Reader : public IReader {
    int id;
    std::string name;
    bool enabled;
    TimeSlot timeSlot;
public:
    Reader(int id, std::string name, const TimeSlot &ts);

    int getId() const override;
    std::string_view getName() const override;
    badge::CLEARANCE_LEVEL getType() const override;
    TimeSlot& getAccessTimeSlot() override;
    bool isEnabled() const override;

    void enable() override;
    void disable() override;
};


#endif