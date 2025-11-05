#include "BuildingReader.h"

#include <utility>

BuildingReader::BuildingReader(std::string n, Server& s) : name(std::move(n)), server(s), enabled(false) {
}

bool BuildingReader::queryAccess(const IBadge &badge) {
    return true;//server->;
}

void BuildingReader::enable(const bool e) {
    enabled = e;
}

std::string_view BuildingReader::getName() const {
    return name;
}

bool BuildingReader::isEnabled() const {
    return enabled;
}
