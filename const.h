#ifndef __CONST_H
#define __CONST_H

namespace badge {
    const typedef enum {
        STUDENT = 0,
        TEACHER = 1,
        DOCTOR = 2,
        CLEANUP = 3,
        STAFF = 4,
        UNKNOWN = -1
    } CLEARANCE_LEVEL;

    inline auto getTypeName(CLEARANCE_LEVEL type) -> std::string_view {
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
            default:
                return "Unknown";
        }
    }

    typedef enum {
        ERR_NONE = -1,
        ERR_UNK_BADGE = 0,
        ERR_UNK_READER = 1,
        ERR_EXPIRED_DATE = 2,
        ERR_CLEARANCE = 3,
        ERR_READER_TIME = 4,
        ERR_READER_DISABLED = 5
    } SERVER_QUERY_ERROR;

    inline auto getErrorName(const SERVER_QUERY_ERROR err) -> std::string_view {
        switch (err) {
            case ERR_NONE:
                return "None";
            case ERR_UNK_BADGE:
                return "Unknown badge";
            case ERR_UNK_READER:
                return "Unknown reader";
            case ERR_EXPIRED_DATE:
                return "Badge has expired";
            case ERR_CLEARANCE:
                return "Low clearance level";
            case ERR_READER_TIME:
                return "Reader is time-disabled";
            case ERR_READER_DISABLED:
                return "Reader is disabled";
            default:
                return "Unknown error";
        }
    }
}

#endif