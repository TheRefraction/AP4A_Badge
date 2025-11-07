#include <ctime>

#include "Badge.h"

Badge::Badge(const int id, IPerson &o) : id(id), owner(o), date() {}

int Badge::getId() const {
    return id;
}

IPerson& Badge::getOwner() const {
    return owner;
}

time_t Badge::getDate() const {
    return date;
}

std::vector<int> Badge::getPermissions() const {
    return permissions;
}

void Badge::setDate(const time_t d) {
    date = d;
}


