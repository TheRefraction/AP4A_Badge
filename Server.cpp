#include "Server.h"

#include <utility>

Server::Server(): name("Default"), running(false) {
}

Server::Server(std::string n): name(std::move(n)), running(false) {
}

void Server::start() {
    this->running = true;
}

void Server::stop() {
    this->running = false;
}

std::string_view Server::get_name() {
    return this->name;
}

bool Server::is_running() const {
    return this->running;
}
