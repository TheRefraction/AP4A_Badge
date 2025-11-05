#ifndef __BUILDINGREADER_H
#define __BUILDINGREADER_H

#include "IReader.h"

class Server;

class BuildingReader : public IReader {
    std::string name;
    Server& server;
    bool enabled;
public:
    BuildingReader(std::string n, Server &s);

    bool queryAccess(const IBadge &badge) override;

    void enable(bool e) override;

    std::string_view getName() const override;
    bool isEnabled() const override;
};


#endif