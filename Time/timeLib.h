#ifndef __TIME_H
#define __TIME_H

#include <chrono>
#include <string>

std::chrono::system_clock::time_point parseDateTime(const std::string& s);
std::string formatDateTime(const std::chrono::system_clock::time_point& tp);


#endif