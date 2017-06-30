#include <iostream>
#include <iomanip>
#include "appt.h"

bool Appointment::lessThan(const Appointment *a2) const
{
   return startTime.lessThan(&a2->startTime);
}

void Appointment::read()
{
    // callee of read(Day *day)
    // orig: 12/5/2003,ECS 30-C,11:00:00 AM,11:50:00 AM,3 Temp
    // after read(Calendar *):
    // ECS 30-C,11:00:00 AM,11:50:00 AM,3 Temp
    char *subjectStr = strtok(NULL, ",");
    subject = new char[strlen(subjectStr) + 1];
    strcpy(subject, subjectStr);
    startTime.read();
    endTime.read();
    char *loc = strtok(NULL, "\n");
    loc = strtok(loc, "/");
    if (loc[strlen(loc)-1] == ' ') {
        loc[strlen(loc)-1] = '\0';
    }
    location = new char[strlen(loc) + 1];
    strcpy(location, loc);
}

void Appointment::print() const
{
    startTime.print();
    std::cout << " ";
    endTime.print();
    std::cout << " " << std::left << std::setfill(' ') << std::setw(13) << subject 
        << " " << location << "\n";

}

void Appointment::destroy()
{
    delete[] subject;
    delete[] location;
}


