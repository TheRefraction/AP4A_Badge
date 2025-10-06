#ifndef __CONST_H
#define __CONST_H

namespace badge {
    typedef enum {
        PUBLIC = 0,
        PROTECTED = 1,
        PRIVATE = 2,
        UNKNOWN = -1
    } SECURITY_LEVEL;
}

#endif