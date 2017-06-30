#include <iostream>
#include <iomanip>

#include "time.h"

bool operator<(const Time &t1, const Time &t2)
{
    if (t1.hour < t2.hour) {
        return true;
    }
    if (t1.hour > t2.hour) {
        return false;
    }
    if (t1.minute < t2.minute) {
        return true;
    }
    return false;
}


std::ostream & operator<<(std::ostream &os, const Time &t)
{
    os << std::setfill('0') << std::right << std::setw(2) << t.hour 
        << ":" << std::setfill('0') << std::right << std::setw(2) << t.minute;
    return os;

}

std::istream & operator>>(std::istream &is, Time &t)
{
    std::string line;
    std::getline(is, line, ':');
    t.hour = atoi(line.c_str());

    std::getline(is, line, ':');
    t.minute = atoi(line.c_str());
    std::getline(is, line, ' '); // ignore seconds
    std::getline(is, line, ','); // before AM or PM
    if (line.c_str()[0] == 'P' && t.hour < 12)
    {
        t.hour += 12;
    }
    return is;
}
