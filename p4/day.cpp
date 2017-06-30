#include <iostream>
#include <iomanip>

#include "day.h"
#include "DayOfWeek.h"

Day::Day(): day(31), month(12), year(9999)
{

}

Day::Day(int day, int month, int year): day(day), month(month), year(year), apptCount(0) 
{

}

bool Day::equal(const Day *d2) const
{
    return day == d2->day && month == d2->month && year == d2->year;
}

bool Day::lessThan(const Day *d2) const
{
    if (year < d2->year) {
        return true;
    }
    if (year > d2->year) {
        return false;
    }
    if (month < d2->month) {
        return true;
    }
    if (month > d2->month) {
        return false;
    }
    if (day < d2->day) {
        return true;
    }
    return false;

}

void Day::read()
{
    // callee of read(Calendar *cal)j
    Appointment *curr = new Appointment;
    curr->read();

    int pos = 0;
    for (; pos < apptCount; pos++) {
        if (curr->lessThan(appts[pos])) {
            break;
        }
    }
    for (int i = apptCount; i > pos; i--) {
        appts[i] = appts[i-1];
    }
    appts[pos] = curr;
    apptCount++;
    Appointment::count += 1;
}

void Day::print() const
{
    for (int i = 0; i < apptCount; i++) {
        appts[i]->print();
    }
}

void Day::subjectSearch(const char *subject) const
{
    DayOfWeek dow; // = new DayOfWeek();

    
    for (int i = 0; i < apptCount; i++)
    {
        if (strcmp(appts[i]->subject, subject) == 0)
        {
            dow.read(month, day, year);
            dow.print();
            appts[i]->print();
        }
    }
}

void Day::destroy()
{
    for (int i = 0; i < apptCount; i++)
    {
        delete appts[i];
    }
}

Day & Day::operator=(const Day &rhs)
{
    if (this == &rhs)
        return *this;
    
    day = rhs.day;
    month = rhs.month;
    year = rhs.year;
    apptCount = rhs.apptCount;
    for (int i = 0; i < apptCount; i++)
    {
        appts[i] = new Appointment(*rhs.appts[i]);
    }
    return *this;
}
