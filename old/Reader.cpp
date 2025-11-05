#include "Reader.h"

#include <utility>

Reader::Reader(Server& s): server(s), name("Default"), enabled(false), level(badge::PUBLIC) {
}

Reader::Reader(Server& s, std::string n): server(s), name(std::move(n)), enabled(false), level(badge::PUBLIC) {
}

std::string_view Reader::get_name() {
    return this->name;
}

bool Reader::is_enabled() const {
    return this->enabled;
}

void Reader::enable(const bool en) {
    this->enabled = en;
}