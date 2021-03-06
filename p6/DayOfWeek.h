
#ifndef DAYOFWEEK_H
#define DAYOFWEEK_H

#include <iostream>

class DayOfWeek {
    char monthName[10];
    int month;
    int day;
    int year;
    char dayName[10];
public:
    DayOfWeek();
    DayOfWeek(int month, int day, int year);
    ~DayOfWeek();



    friend bool operator==(const DayOfWeek &, char c);
    
    friend std::ostream & operator<<(std::ostream &, const DayOfWeek &);
    friend std::istream & operator>>(std::istream &, DayOfWeek &);
};

#endif
