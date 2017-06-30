#include "DayOfWeek.h"
#include <iostream>
#include <iomanip>
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
    char date[30];

    strcpy(date, dow.dayName);
    strcat(date, ", ");
    strcat(date, dow.monthName);
    strcat(date, " ");
    char dayStr[3] = {'0', '0', '\0'};
    
    if (dow.day >= 10) {
        dayStr[0] += dow.day / 10;
        dayStr[1] += dow.day % 10;
    } else {
        dayStr[0] += dow.day;
        dayStr[1] = '\0';
    }
    strcat(date, dayStr);
    os << std::left << std::setw(30) << std::setfill(' ') << date;
    return os;

}


