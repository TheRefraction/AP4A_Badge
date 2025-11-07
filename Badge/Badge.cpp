#include "Badge.h"

#include <utility>

Badge::Badge(const unsigned int id, std::shared_ptr<IPerson> o) : id(id), owner(std::move(o)) {
}

unsigned int Badge::getId() const {
    return id;
}

std::shared_ptr<IPerson> Badge::getOwner() const {
    return owner;
}

std::chrono::system_clock::time_point Badge::getDate() const {
    return date;
}

std::set<unsigned int> Badge::getPermissions() const {
    return permissions;
}

bool Badge::hasPermission(const unsigned int perm) const {
    return permissions.find(perm) != permissions.end();
}

void Badge::addPermission(const unsigned int perm) {
    permissions.insert(perm);
}

void Badge::removePermission(const unsigned int perm) {
    permissions.erase(perm);
}

void Badge::clearPermissions() {
    permissions.clear();
}

void Badge::setDate(const std::chrono::system_clock::time_point d) {
    date = d;
}


