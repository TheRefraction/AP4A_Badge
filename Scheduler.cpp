#include <chrono>

#include "Scheduler.h"

Scheduler::Scheduler(): running(false) {
}

void Scheduler::start() {
    running = true;
}

void Scheduler::run() {
    if (running) {
        for (auto &s : servers) {
            std::cout << s << std::endl;
            if (s.is_running()) {
                simulate(s);
            }
        }

        // Get input to stop scheduler
        // this->running = false;
    }

}

void Scheduler::simulate(Server &s) {
    //simulate operations here
}


bool Scheduler::is_running() {
    return this->running;
}
