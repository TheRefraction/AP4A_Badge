#include <iostream>

#include "Scheduler.h"

#define DEBUG

int main() {
    #ifdef DEBUG
        std::cout << std::unitbuf;
    #endif

    Scheduler scheduler;
    scheduler.start();

    while (scheduler.is_running()) {
        scheduler.run();
    }

    std::cout << "Done!" << std::endl;

    return 0;
}