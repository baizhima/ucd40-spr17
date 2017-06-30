#include <iostream>
#include <iomanip>

#include "day.h"

void Day::create(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
    apptCount = 0;
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
}

void Day::print() const
{
    for (int i = 0; i < apptCount; i++) {
        appts[i]->print();
    }
}

void Day::subjectSearch(const char *subject) const
{
    for (int i = 0; i < apptCount; i++)
    {
        if (strcmp(appts[i]->subject, subject) == 0)
        {
            std::cout << std::right << std::setw(2) << std::setfill(' ') << month
                 << "/" << std::setw(2) << std::right << day << "/" << year << " ";
            appts[i]->print();
        }
    }
}

void Day::destroy()
{
    for (int i = 0; i < apptCount; i++)
    {
        appts[i]->destroy();
        delete appts[i];
    }
}
