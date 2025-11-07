#ifndef __STAFFREADER_H
#define __STAFFREADER_H

#include "Reader.h"

class StaffReader : public Reader{
public:
    badge::CLEARANCE_LEVEL getType() const override;
};


#endif