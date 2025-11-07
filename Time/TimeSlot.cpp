#include <stdexcept>

#include "TimeSlot.h"
#include "timeLib.h"

TimeSlot::TimeSlot(const std::string &startStr, const std::string &endStr) : start(parseDateTime(startStr)), end(parseDateTime(endStr)) {
    if (end <= start) {
        throw std::runtime_error("Invalid time slot format");
    }
}

std::string TimeSlot::toString() const {
    return formatDateTime(start) + " -> " + formatDateTime(end);
}

bool TimeSlot::overlaps(const TimeSlot& o) const {
    return (start < o.end) && (o.start < end);
}

bool TimeSlot::contains(const std::chrono::system_clock::time_point& t) const {
    return (t >= start) && (t < end);
}
