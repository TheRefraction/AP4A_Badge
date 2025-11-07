#include "timeLib.h"

#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>

std::chrono::system_clock::time_point parseDateTime(const std::string& s) {
    std::tm tm = {};
    std::istringstream ss(s);

    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");

    if (ss.fail()) {
        throw std::runtime_error("Invalid datetime format");
    }

    std::time_t tt = std::mktime(&tm);
    return std::chrono::system_clock::from_time_t(tt);
}

std::string formatDateTime(const std::chrono::system_clock::time_point& tp) {
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);
    std::tm tm = *std::localtime(&tt);

    std::ostringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M");
    return ss.str();
}