#include "day.h"

void create(Day *d, int day, int month, int year)
{
    d->day = day;
    d->month = month;
    d->year = year;
    d->apptCount = 0;
}

bool equal(Day *d1, Day *d2)
{
    return d1->day == d2->day && d1->month == d2->month && d1->year == d2->year;
}

bool lessThan(Day *d1, Day *d2)
{
    if (d1->year < d2->year) {
        return true;
    }
    if (d1->year > d2->year) {
        return false;
    }
    if (d1->month < d2->month) {
        return true;
    }
    if (d1->month > d2->month) {
        return false;
    }
    if (d1->day < d2->day) {
        return true;
    }
    return false;

}

void read(Day *day) {
    // callee of read(Calendar *cal)j
    Appointment *curr = (Appointment *) malloc(sizeof(Appointment));
    read(curr);
        
    int pos = 0;
    for (; pos < day->apptCount; pos++) {
        if (lessThan(curr, day->appts[pos])) {
            break;
        }
    }
    for (int i = day->apptCount; i > pos; i--) {
        day->appts[i] = day->appts[i-1];
    }
    day->appts[pos] = curr;
    day->apptCount++;
}

void print(Day *day) {
    for (int i = 0; i < day->apptCount; i++) {
        print(day->appts[i]);
    }
}

void subjectSearch(Day *d, char *subject)
{
    for (int i = 0; i < d->apptCount; i++)
    {
        if (strcmp(d->appts[i]->subject, subject) == 0)
        {
            printf("%2d/%2d/%d ", d->month, d->day, d->year);
            print(d->appts[i]);
        }
    }
}

void destroy(Day *d)
{
    for (int i = 0; i < d->apptCount; i++)
    {
        destroy(d->appts[i]);
    }
}
