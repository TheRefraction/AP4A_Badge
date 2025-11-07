#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include <vector>

#include "Server.h"

class Scheduler {
    std::vector<Server> servers;
    bool running;
public:
    Scheduler();

    void start();
    void run();
    void simulate(Server& s);

    bool isRunning();
};


#endif