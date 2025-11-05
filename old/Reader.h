#ifndef __READER_H
#define __READER_H

#include <iomanip>
#include <string>


class Server;

class Reader {
    Server& server;
    std::string name;
    bool enabled;
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
    bool is_enabled() const;
    //Setters
    void enable(bool en);
};


#endif