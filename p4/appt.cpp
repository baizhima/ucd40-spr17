#include <iostream>
#include <iomanip>
#include "appt.h"



Appointment::Appointment(): subject(NULL), location(NULL)
{
    
}

Appointment::Appointment(const Appointment &rhs): startTime(rhs.startTime), endTime(rhs.endTime)
{
   subject = new char[strlen(rhs.subject) + 1]; 
   strcpy(subject, rhs.subject);
   location = new char[strlen(rhs.location) + 1];
   strcpy(location, rhs.location);
}

bool Appointment::lessThan(const Appointment *a2) const
{
   return startTime.lessThan(&a2->startTime);
}

void Appointment::read()
{
    // callee of read(Day *day)
    // orig: 12/5/2003,ECS 30-C,11:00:00 AM,11:50:00 AM,3 Temp
    // 7/28/1995,Russian,1:10:00 PM,1:30:00 PM,106 Wellman
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


Appointment::~Appointment()
{
    delete[] subject;
    delete[] location;
}
