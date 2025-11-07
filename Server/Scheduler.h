#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include <vector>
#include <memory>

#include "Server.h"

class Scheduler {
    std::vector<std::shared_ptr<Server>> servers;
    bool running;
    unsigned int numSimulations;
    unsigned int sleepTime;
public:
    Scheduler(unsigned int n, unsigned int s);

    void start();
    void run();
    template<typename K, typename V> K randomKey(const std::map<K,V>& m);
    void simulate(const std::shared_ptr<Server>& s);

    bool isRunning();
};


#endif