#ifndef __ROOMREADER_H
#define __ROOMREADER_H

#include "Reader.h"

class RoomReader : public Reader {
public:
    RoomReader(const unsigned int id, std::string name, std::string startTime, std::string endTime) : Reader(id, std::move(name), std::move(startTime), std::move(endTime)) {}
    badge::CLEARANCE_LEVEL getType() const override {return badge::CLEARANCE_LEVEL::STUDENT;}
};


#endif