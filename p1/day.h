#ifndef DAY_H
#define DAY_H

#include <cstdio>
#include <cstdlib>

#include "appt.h"


typedef struct {
    short day;
    short month;
    short year;
    Appointment *appts[8];
    short apptCount;

} Day;

void create(Day *d, int day, int month, int year);

void destroy(Day *d);

bool equal(Day *d1, Day *d2);

bool lessThan(Day *d1, Day *d2);

void read(Day *d);

void print(Day *d);

void subjectSearch(Day *d, char *subject);

#endif
