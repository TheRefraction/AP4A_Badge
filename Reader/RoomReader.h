#ifndef __ROOMREADER_H
#define __ROOMREADER_H

#include "Reader.h"

class RoomReader : public Reader {
public:
    badge::CLEARANCE_LEVEL getType() const override;
};


#endif