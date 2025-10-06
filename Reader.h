#ifndef __READER_H
#define __READER_H

#include "const.h"
#include "Server.h"

class Reader {
    Server& server;
    std::string name;
    bool enabled;
    badge::SECURITY_LEVEL level;
public:
    Reader(Server& s);
    Reader(Server& s, std::string n);

    friend std::ostream& operator<<(std::ostream& o, Reader& r)
    {
        o << r.get_name();

        return o;
    }
    // Getters
    std::string_view get_name();
    badge::SECURITY_LEVEL get_level() const;
    bool is_enabled() const;
    //Setters
    void set_level(badge::SECURITY_LEVEL l);
    void enable(bool en);
};


#endif