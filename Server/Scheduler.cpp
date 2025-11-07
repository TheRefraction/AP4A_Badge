#include <chrono>
#include <thread>
#include <fstream>
#include <random>

#include "Scheduler.h"

Scheduler::Scheduler(const unsigned int n, const unsigned int s): running(false), numSimulations(n), sleepTime(s) {
}

void Scheduler::start() {
    std::cout << "Starting Scheduler...\n";

    std::ifstream configFile;
    configFile.open("servers.txt");

    if (configFile.is_open()) {
        std::string line;

        while (std::getline(configFile, line)) {
            servers.push_back(std::make_shared<Server>(line));
        }

        configFile.close();
    } else throw std::runtime_error("File servers.txt could not be open");

    for (auto &server : servers) {
        server->start();
    }

    std::cout << "Scheduler started!\n";

    running = true;
}

void Scheduler::run() {
    if (running) {
        for (const auto& s : servers) {
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

template<typename K, typename V> K Scheduler::randomKey(const std::map<K,V>& m) {
    if (m.empty()) throw std::runtime_error("Map is empty");

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, m.size() - 1);

    size_t index = dist(gen);

    auto it = m.begin();
    std::advance(it, index);

    return it->first;
}

void Scheduler::simulate(const std::shared_ptr<Server>& s) {
    // size() est en O(1)
    const unsigned int badgeId = randomKey(s->getBadges());
    const unsigned int readerId = randomKey(s->getReaders());

    bool success = s->queryAccess(badgeId, readerId);

    std::string prefix = success ? "log_s_" : "log_f_";
    std::string fileName = prefix + s->getName() + ".log";
    std::ofstream file(fileName, std::ios::out | std::ios::app);

    if (file.is_open()) {
        file << *s;
    } else {
        std::cout << "Could not open file " << fileName << std::endl;
    }

    file.close();

    std::cout << *s;

    s->clearError();
}


bool Scheduler::isRunning() {
    return running;
}
