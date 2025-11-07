#ifndef __LABREADER_H
#define __LABREADER_H

#include "Reader.h"

class LabReader : public Reader {
public:
    LabReader(const unsigned int id, std::string name, std::string startTime, std::string endTime) : Reader(id, std::move(name), std::move(startTime), std::move(endTime)) {}
    badge::CLEARANCE_LEVEL getType() const override {return badge::CLEARANCE_LEVEL::DOCTOR;}
};

#endif
