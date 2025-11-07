#include "Reader.h"

Reader::Reader(const int id, std::string name, const TimeSlot &ts) : id(id), name(std::move(name)), enabled(false),
                                                                     timeSlot(ts) {
}

int Reader::getId() const {
    return id;
}

std::string_view Reader::getName() const {
    return name;
}

badge::CLEARANCE_LEVEL Reader::getType() const {
    return badge::CLEARANCE_LEVEL::UNKNOWN;
}

TimeSlot & Reader::getAccessTimeSlot() {
    return timeSlot;
}

bool Reader::isEnabled() const {
    return enabled;
}

void Reader::enable() {
    enabled = true;
}

void Reader::disable() {
    enabled = false;
}
