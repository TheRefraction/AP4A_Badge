#include "Person.h"

#include <utility>

Person::Person(std::string name) : name(std::move(name)) {
}

std::string_view Person::getName() const {
    return name;
}

badge::CLEARANCE_LEVEL Person::getType() const {
    return badge::CLEARANCE_LEVEL::UNKNOWN;
}
