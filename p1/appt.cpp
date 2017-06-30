#include "appt.h"
#include <cstdio>

bool lessThan(Appointment *a1, Appointment *a2)
{
   return lessThan(a1->startTime, a2->startTime);
}

void read(Appointment *appt)
{
    // callee of read(Day *day)
    // orig: 12/5/2003,ECS 30-C,11:00:00 AM,11:50:00 AM,3 Temp
    // after read(Calendar *):
    // ECS 30-C,11:00:00 AM,11:50:00 AM,3 Temp
    char *subject = strtok(NULL, ",");
    appt->subject = (char *) malloc(sizeof(char) * (strlen(subject) + 1));
    strcpy(appt->subject, subject);
    read(&appt->startTime);
    read(&appt->endTime);
    char *location = strtok(NULL, "\n");
    location = strtok(location, "/");
    if (location[strlen(location)-1] == ' ') {
        location[strlen(location)-1] = '\0';
    }
    appt->location = (char *) malloc(sizeof(char) * (strlen(location) + 1));
    strcpy(appt->location, location);
}

void print(Appointment *appt)
{
    print(appt->startTime);
    printf(" ");
    print(appt->endTime);
    printf(" %-13s %s\n", 
            appt->subject, appt->location);
}

void destroy(Appointment *appt)
{
    free(appt->subject);
    free(appt->location);
}


