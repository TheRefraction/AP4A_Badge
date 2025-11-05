#include "Server.h"

#include <utility>

Server::Server(): name("Default"), running(false) {
}

Server::Server(std::string n): name(std::move(n)), running(false) {
}

void Server::start() {
    running = true;
}

void Server::stop() {
    running = false;
}

std::string_view Server::getName() {
    return name;
}

bool Server::isRunning() const {
    return running;
}
