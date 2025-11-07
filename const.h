#ifndef __CONST_H
#define __CONST_H

// Namespace defined to avoid collisions
namespace badge {
    // Enum for clearance used according to IReader and IPerson
    enum class CLEARANCE_LEVEL {
        STUDENT = 0,
        TEACHER = 1,
        DOCTOR = 2,
        CLEANUP = 3,
        STAFF = 4,
        UNKNOWN = -1
    };

    // Helper function that prints what the Clearance level means
    inline auto getTypeName(CLEARANCE_LEVEL type) -> std::string_view {
        switch (type) {
            case CLEARANCE_LEVEL::STUDENT:
                return "Student";
            case CLEARANCE_LEVEL::TEACHER:
                return "Teacher";
            case CLEARANCE_LEVEL::DOCTOR:
                return "Doctor";
            case CLEARANCE_LEVEL::CLEANUP:
                return "Cleanup staff";
            case CLEARANCE_LEVEL::STAFF:
                return "Staff";
            default:
                return "Unknown";
        }
    }

    // Enum for error code used according in Server
    enum class SERVER_QUERY_ERROR {
        ERR_NONE = -1,
        ERR_UNK_BADGE = 0,
        ERR_UNK_READER = 1,
        ERR_EXPIRED_DATE = 2,
        ERR_CLEARANCE = 3,
        ERR_READER_TIME = 4,
        ERR_READER_DISABLED = 5
    };

    // Helper function that prints what a server error code means
    inline auto getErrorName(const SERVER_QUERY_ERROR err) -> std::string_view {
        switch (err) {
            case SERVER_QUERY_ERROR::ERR_NONE:
                return "None";
            case SERVER_QUERY_ERROR::ERR_UNK_BADGE:
                return "Unknown badge";
            case SERVER_QUERY_ERROR::ERR_UNK_READER:
                return "Unknown reader";
            case SERVER_QUERY_ERROR::ERR_EXPIRED_DATE:
                return "Badge has expired";
            case SERVER_QUERY_ERROR::ERR_CLEARANCE:
                return "Low clearance level";
            case SERVER_QUERY_ERROR::ERR_READER_TIME:
                return "Reader is time-disabled";
            case SERVER_QUERY_ERROR::ERR_READER_DISABLED:
                return "Reader is disabled";
            default:
                return "Unknown error";
        }
    }
}

#endif