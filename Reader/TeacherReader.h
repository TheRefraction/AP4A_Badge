#ifndef __TEACHERREADER_H
#define __TEACHERREADER_H

#include "Reader.h"

class TeacherReader : public Reader {
public:
    badge::CLEARANCE_LEVEL getType() const override;
};


#endif