#include <iostream>
#include <cstdlib>

#include "Server/Scheduler.h"

#define DEBUG

int main() {
    #ifdef DEBUG
        std::cout << std::unitbuf;
    #endif

    unsigned int numSim{0};
    unsigned int sleepTime{0};

    while (true) {
        std::cout << "Enter number of simulations: ";
        if (std::cin >> numSim && numSim >= 1)
            break;

        std::cout << "Error: number must be greater than 0.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        std::cout << "Enter sleep time (milliseconds): ";
        if (std::cin >> sleepTime && sleepTime >= 1)
            break;

        std::cout << "Error: number must be greater than 0.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    Scheduler scheduler = Scheduler(numSim, sleepTime);
    scheduler.start();

    while (scheduler.isRunning()) {
        scheduler.run();
    }

    std::cout << "Done!" << std::endl;

    return EXIT_SUCCESS;
}