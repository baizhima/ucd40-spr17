#ifndef APPT_H
#define APPT_H

#include "time.h"

#include <cstring>
#include <cstdlib>

typedef struct {
    Time startTime;
    Time endTime;
    char *subject;
    char *location;
} Appointment;

void read(Appointment *);

void print(Appointment *);

bool lessThan(Appointment *, Appointment *);

void destroy(Appointment *);

#endif
