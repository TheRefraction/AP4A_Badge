#ifndef __SERVER_H
#define __SERVER_H

#include <iomanip>
#include <iostream>
#include <string>

class Server {
    std::string name;
    bool running;
public:
    Server();
    Server(std::string n);

    friend std::ostream& operator<<(std::ostream& o, Server& s)
    {
        o << "Server " << s.getName() << ":\n";
        o << "Running: " << s.isRunning() << "\n";

        return o;
    }
    // Methods
    void start();
    void stop();
    // Getters
    std::string_view getName();
    bool isRunning() const;
};


#endif