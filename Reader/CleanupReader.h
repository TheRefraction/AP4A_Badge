#ifndef _CLEANUPREADER_H
#define _CLEANUPREADER_H

#include "Reader.h"

class CleanupReader : public Reader {
public:
    badge::CLEARANCE_LEVEL getType() const override;
};


#endif