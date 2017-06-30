#include "DayOfWeek.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

DayOfWeek::DayOfWeek()
{
    memset(this, 0, sizeof(*this));
}

DayOfWeek::~DayOfWeek()
{

}


void DayOfWeek::read(int mm, int dd, int yyyy)
{
    int beginMonth = 1, beginDay = 1, beginYear = 1990;
    int offsetDays = ((yyyy - beginYear) *31*12 + (mm - beginMonth) *31 + (dd - beginDay));
    std::ifstream inf("DOW.dat", std::ios::in | std::ios::binary);
    memset(this, 0, sizeof(*this)); 
    inf.seekg(offsetDays * sizeof(*this));
    inf.read((char *)this, sizeof(DayOfWeek));
    inf.close(); 
}

void DayOfWeek::print()
{
    char date[30];

    strcpy(date, dayName);
    strcat(date, ", ");
    strcat(date, monthName);
    strcat(date, " ");
    char dayStr[3] = {'0', '0', '\0'};
    
    if (day >= 10) {
        dayStr[0] += day / 10;
        dayStr[1] += day % 10;
    } else {
        dayStr[0] += day;
        dayStr[1] = '\0';
    }
    strcat(date, dayStr);
    std::cout << std::left << std::setw(30) << std::setfill(' ') << date;

}

