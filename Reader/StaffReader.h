#ifndef __STAFFREADER_H
#define __STAFFREADER_H

#include "Reader.h"

class StaffReader : public Reader{
public:
    StaffReader(const unsigned int id, std::string name, std::string startTime, std::string endTime) : Reader(id, std::move(name), std::move(startTime), std::move(endTime)) {}
    badge::CLEARANCE_LEVEL getType() const override {return badge::CLEARANCE_LEVEL::STAFF;}
};


#endif