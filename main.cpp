#include <iostream>
#include <cstdlib>

#include "Server/Scheduler.h"

#define DEBUG

int main() {
    #ifdef DEBUG
        std::cout << std::unitbuf;
    #endif

    Scheduler scheduler;
    scheduler.start();

    while (scheduler.isRunning()) {
        scheduler.run();
    }

    std::cout << "Done!" << std::endl;

    return EXIT_SUCCESS;
}