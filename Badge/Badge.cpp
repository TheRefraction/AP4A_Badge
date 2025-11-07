#include "Badge.h"

Badge::Badge(const int id, IPerson &o, const TimeSlot &ts) : id(id), owner(o), timeSlot(ts) {
}

int Badge::getId() const {
    return id;
}

IPerson& Badge::getOwner() const {
    return owner;
}

std::chrono::system_clock::time_point Badge::getDate() const {
    return date;
}

TimeSlot& Badge::getAccessTimeSlot() {
    return timeSlot;
}

std::set<int> Badge::getPermissions() const {
    return permissions;
}

bool Badge::hasPermission(const int perm) const {
    return permissions.find(perm) != permissions.end();
}

void Badge::addPermission(const int perm) {
    permissions.insert(perm);
}

void Badge::removePermission(const int perm) {
    permissions.erase(perm);
}

void Badge::clearPermissions() {
    permissions.clear();
}

void Badge::setDate(const std::chrono::system_clock::time_point d) {
    date = d;
}


