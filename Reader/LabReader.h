#ifndef __LABREADER_H
#define __LABREADER_H

#include "Reader.h"

class LabReader : public Reader {
public:
    badge::CLEARANCE_LEVEL getType() const override;
};

#endif
