#ifndef __SERVER_H
#define __SERVER_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Reader.h"

class Server {
    std::string name;
    std::vector<Reader> readers;
    bool running;
public:
    Server();
    Server(std::string n);

    friend std::ostream& operator<<(std::ostream& o, Server& s)
    {
        std::cout << "Server " << s.get_name() << ":\n";
        std::cout << "Running: " << s.is_running() << "\n";
        std::cout << "Loaded Readers:\n";

        for (auto &r : s.readers) {
            std::cout << std::setw(16) << r << std::endl;
        }

        return o;
    }
    // Methods
    void start();
    void stop();
    // Getters
    std::string_view get_name();
    bool is_running() const;
};


#endif