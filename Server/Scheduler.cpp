#include <chrono>
#include <thread>
#include <random>
#include <fstream>

#include "Scheduler.h"

Scheduler::Scheduler(const unsigned int n, const unsigned int s): running(false), numSimulations(n), sleepTime(s) {
}

void Scheduler::start() {
    std::cout << "Starting Scheduler...\n";

    std::ifstream configFile;
    configFile.open("servers.txt");

    if (!configFile.is_open()) {
        throw("Could not open file servers.txt");
    }

    std::string line;

    while (std::getline(configFile, line)) {
        servers.push_back(std::make_shared<Server>(line));
    }

    configFile.close();

    running = true;
}

void Scheduler::run() {
    if (running) {
        for (const auto& s : servers) {
            std::cout << s << std::endl;
            if (s->isRunning()) {
                simulate(s);
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

        numSimulations--;
        if (numSimulations == 0) {
            running = false;
        }
    }
}

int Scheduler::randomInt(const int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, max);

    return dist(gen);
}

void Scheduler::simulate(const std::shared_ptr<Server>& s) {
    // size() est en O(1)
    const int badgeId = randomInt(s->getBadges().size() - 1);
    const int readerId = randomInt(s->getReaders().size() - 1);

    std::ofstream file;
    std::string fileName;

    bool success = s->queryAccess(badgeId, readerId);
    if (success) {
        fileName = "log_s_" + s->getName() +".log";
        file.open(fileName, std::ios::out | std::ios::app);

        if (file.is_open()) {
            file << s;
        } else std::cout << "Could not open file" << fileName << std::endl;
    } else {
        fileName = "log_f_" + s->getName() +".log";
        file.open(fileName, std::ios::out | std::ios::app);

        if (file.is_open()) {
            file << s;
        } else std::cout << "Could not open file" << fileName << std::endl;
    }

    file.close();

    std::cout << s;

    //s->clearError();
}


bool Scheduler::isRunning() {
    return running;
}
