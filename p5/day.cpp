#include <iostream>
#include <iomanip>
#include <fstream>
#include "day.h"
#include "DayOfWeek.h"

Day::Day(): day(31), month(12), year(9999)
{

}

Day::Day(int day, int month, int year): day(day), month(month), year(year)
{

}

bool operator==(const Day &d1, const Day &d2)
{
    return d1.day == d2.day && d1.month == d2.month && d1.year == d2.year;
}

bool operator<(const Day &d1, const Day &d2)
{
    if (d1.year < d2.year) {
        return true;
    }
    if (d1.year > d2.year) {
        return false;
    }
    if (d1.month < d2.month) {
        return true;
    }
    if (d1.month > d2.month) {
        return false;
    }
    if (d1.day < d2.day) {
        return true;
    }
    return false;

}

std::istream & operator>>(std::istream &is, Day &d)
{
    Appointment *curr = new Appointment;
    is >> *curr;
    d += curr;
    Appointment::count += 1;

    return is;
}

std::ostream & operator<<(std::ostream &os, const Day &d)
{
    os << d.appts;

    return os;
}

void Day::subjectSearch(const char *subject) const
{
    DayOfWeek dow(month, day, year); 
    std::ifstream is("DOW.dat", std::ios::binary | std::ios::in);

    Appointment *appt = NULL;
    while ((appt = appts.find(subject)))
    {
        if (strcmp(appt->subject, subject) == 0)
        {
            is >> dow;
            std::cout << dow;
            std::cout << *appt;
        }
    }
   

    is.close();
}

Day::~Day()
{
}

Day & Day::operator=(const Day &rhs)
{
    if (this == &rhs)
        return *this;
    
    day = rhs.day;
    month = rhs.month;
    year = rhs.year;
    appts = rhs.appts;

    return *this;
}

Day & Day::operator+=(Appointment *& appt)
{
   appts += appt;
   return *this;
}
