#ifndef __SERVER_H
#define __SERVER_H

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <memory>

#include "../Reader/IReader.h"
#include "../Badge/IBadge.h"

class Server {
    std::string name;
    bool running;
    badge::SERVER_QUERY_ERROR errorId;
    std::map<unsigned int, std::shared_ptr<IReader>> readers;
    std::map<unsigned int, std::shared_ptr<IBadge>> badges;
public:
    Server();
    Server(std::string n);

    bool queryAccess(unsigned int badgeID, unsigned int readerID);
    bool queryAccess(const IBadge& badge, const IReader& reader);

    std::string_view getName();
    bool isRunning() const;
    badge::SERVER_QUERY_ERROR getErrorId() const;
    std::map<unsigned int, std::shared_ptr<IReader>>& getReaders();
    std::map<unsigned int, std::shared_ptr<IBadge>>& getBadges();

    void start();
    void stop();
    void clearError();

    friend std::ostream& operator<<(std::ostream& o, Server& s) {
        o << "Server " << s.getName() << ":\n";
        o << "Running: " << s.isRunning() << "\n";

        return o;
    }
};


#endif