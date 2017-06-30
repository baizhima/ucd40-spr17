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

Day::~Day()
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

const Appointment * operator>>(std::istream &is, Day &d)
{
    // when this function is called, std::istream & is
    // 1,Psychiatry,10:10:00 AM,12:50:00 PM,6 Olson,WF,10

    std::string token;
    std::getline(is, token, ',');
    int classType = atoi(token.c_str());

    Appointment *curr;
    switch (classType)
    {
        case 0: curr = new Appointment; curr->read(is); std::getline(is,token); break;
        case 1: curr = new WeeklyAppointment; curr->read(is); break;
        default: std::cout << "invalid classType " << classType << "\n"; exit(1);
    }
    d += curr;

    return curr;
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
            std::cout << *appt; // dereference will dynamically dispatch, WeeklyAppt can be printed
            std::cout << std::endl;
        }
    }
   

    is.close();
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
   Appointment::count += 1;
   return *this;
}

Day & Day::operator+=(const WeeklyAppointment &appt)
{
    Appointment *newAppt = new WeeklyAppointment(appt);
    appts += newAppt;
    Appointment::count += 1;
    return *this;
}

