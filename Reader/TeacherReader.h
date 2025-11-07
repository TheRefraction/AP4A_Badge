#ifndef __TEACHERREADER_H
#define __TEACHERREADER_H

#include "Reader.h"

class TeacherReader : public Reader {
public:
    TeacherReader(const unsigned int id, std::string name, std::string startTime, std::string endTime) : Reader(id, std::move(name), std::move(startTime), std::move(endTime)) {}
    badge::CLEARANCE_LEVEL getType() const override {return badge::CLEARANCE_LEVEL::TEACHER;}
};


#endif