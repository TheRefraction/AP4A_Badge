#include "Badge.h"

Badge::Badge(IPerson* p) : id(nextId++), owner(p) {}

int Badge::getId() const {
    return id;
}

IPerson* Badge::getOwner() const {
    return owner;
}