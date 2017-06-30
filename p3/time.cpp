#include <iostream>
#include <iomanip>

#include "time.h"

bool Time::lessThan(const Time *t2) const
{
    if (hour < t2->hour) {
        return true;
    }
    if (hour > t2->hour) {
        return false;
    }
    if (minute < t2->minute) {
        return true;
    }
    return false;

}

void Time::print() const
{
    std::cout << std::setfill('0') << std::setw(2) << hour 
        << ":" << std::setfill('0') << std::setw(2) << minute;

}

void Time::read()
{

    hour = atoi(strtok(NULL, ":"));
    minute = atoi(strtok(NULL, ":"));
    strtok(NULL, " ");  // ignore seconds
    char *ptr = strtok(NULL, ","); // before AM or PM
    if (*ptr == 'P' && hour < 12)
    {
        hour += 12;
    }

}
