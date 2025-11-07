#ifndef __TIMESLOT_H
#define __TIMESLOT_H

#include <chrono>
#include <string>

class TimeSlot {
public:
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;

    TimeSlot(const std::string& startStr, const std::string& endStr);

    std::string toString() const;

    bool overlaps(const TimeSlot &o) const;
    bool contains(const std::chrono::system_clock::time_point& tp) const;
};


#endif