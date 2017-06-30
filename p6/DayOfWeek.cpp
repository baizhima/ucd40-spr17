#include "DayOfWeek.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

DayOfWeek::DayOfWeek()
{
    memset(this, 0, sizeof(*this));
}

DayOfWeek::DayOfWeek(int month, int day, int year): month(month), day(day), year(year)
{

}

DayOfWeek::~DayOfWeek()
{

}

bool operator==(const DayOfWeek &dow, char c)
{
    switch (c)
    {
        case 'M': return strcmp(dow.dayName, "Monday") == 0;
        case 'T': return strcmp(dow.dayName, "Tuesday") == 0;
        case 'W': return strcmp(dow.dayName, "Wednesday") == 0;
        case 'R': return strcmp(dow.dayName, "Thursday") == 0;
        case 'F': return strcmp(dow.dayName, "Friday") == 0;
        case 'S': return strcmp(dow.dayName, "Saturday") == 0;
        case 'U': return strcmp(dow.dayName, "Sunday") == 0;
        default: std::cout << "invalid char:" << c << "\n"; return false;
    }
    
}

std::istream & operator>>(std::istream &is, DayOfWeek &dow)
{
    int beginMonth = 1, beginDay = 1, beginYear = 1990;
    int offsetDays = ((dow.year - beginYear) *31*12 + 
                (dow.month - beginMonth) *31 + (dow.day - beginDay));
    is.seekg(offsetDays * sizeof(DayOfWeek));
    is.read((char *)&dow, sizeof(DayOfWeek));
    return is;
}

std::ostream & operator<<(std::ostream &os, const DayOfWeek &dow)
{
    std::stringstream ss;
    ss << dow.dayName << ", " << dow.monthName << " " << dow.day << ", " << dow.year;
    os << std::left << std::setw(30) << std::setfill(' ') << ss.str();
    return os;

}


