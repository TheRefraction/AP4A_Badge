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
    long bufferId[2];   // long because -1 means undefined, and should include unsigned int interval
    std::map<unsigned int, std::shared_ptr<IReader>> readers;
    std::map<unsigned int, std::shared_ptr<IBadge>> badges;
public:
    Server();
    Server(std::string n);
    ~Server();

    bool queryAccess(unsigned int badgeID, unsigned int readerID);
    bool queryAccess(const IBadge& badge, const IReader& reader);

    const std::string& getName() const;
    bool isRunning() const;
    badge::SERVER_QUERY_ERROR getErrorId() const;
    std::map<unsigned int, std::shared_ptr<IReader>>& getReaders();
    std::map<unsigned int, std::shared_ptr<IBadge>>& getBadges();

    void start();
    void stop();
    void clearError();

    friend std::ostream& operator<<(std::ostream& o, Server& s) {
        auto tp = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(tp);

        std::tm local{};
        #ifdef _WIN32
        localtime_s(&local, &t);
        #else
        localtime_r(&t, &local);
        #endif

        o << "[" << std::put_time(&local, "%Y-%m-%d %H:%M:%S") << "] Server<Name:" << s.getName() << ", Running:" << s.isRunning() << ">";

        unsigned int badgeId = s.bufferId[0];
        unsigned int readerId = s.bufferId[1];

        if (badgeId > -1 && readerId > -1) {
            std::shared_ptr<IBadge> badge = s.getBadges().at(badgeId);
            std::shared_ptr<IReader> reader = s.getReaders().at(readerId);

            o << "\nAcquisition between Badge<Owner:" << badge->getOwner()->getName() << ",Clearance:" << badge->getOwner()->getType() << ">";
            o << "\nand Reader<Name:" << reader->getName() << ",Clearance:" << reader->getType() << ",Enabled:" << reader->isEnabled() << "> :";

            if (s.getErrorId() == badge::ERR_NONE) {
                o << "SUCCESS!";
            } else {
                o << "FAILURE:" << badge::getErrorName(s.getErrorId());
            }
        }

        o << std::endl;

        s.clearError();

        return o;
    }
};


#endif