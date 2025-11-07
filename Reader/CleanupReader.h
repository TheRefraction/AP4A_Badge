#ifndef _CLEANUPREADER_H
#define _CLEANUPREADER_H

#include "Reader.h"

class CleanupReader : public Reader {
public:
    CleanupReader(const unsigned int id, std::string name, std::string startTime, std::string endTime) : Reader(id, std::move(name), std::move(startTime), std::move(endTime)) {}
    badge::CLEARANCE_LEVEL getType() const override {return badge::CLEARANCE_LEVEL::CLEANUP;}
};


#endif