#ifndef __CONST_H
#define __CONST_H

namespace badge {
    const typedef enum {
        STUDENT = 0,
        TEACHER = 1,
        DOCTOR = 2,
        CLEANUP = 3,
        STAFF = 4,
        GUEST = 5,
        UNKNOWN = -1
    } CLEARANCE_LEVEL;

    inline std::string_view getTypeName(CLEARANCE_LEVEL type) {
        switch (type) {
            case STUDENT:
                return "Student";
            case TEACHER:
                return "Teacher";
            case DOCTOR:
                return "Doctor";
            case CLEANUP:
                return "Cleanup staff";
            case STAFF:
                return "Staff";
            case GUEST:
                return "Guest";
            default:
                return "Unknown";
        }
    }
}

#endif