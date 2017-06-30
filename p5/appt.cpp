#include <iostream>
#include <iomanip>
#include "appt.h"

int Appointment::count = 0;

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


bool operator<(const Appointment &a1, const Appointment &a2)
{
    return a1.startTime < a2.startTime;
}

std::istream & operator>>(std::istream &is, Appointment &appt)
{
    // orig: 12/5/2003,ECS 30-C,11:00:00 AM,11:50:00 AM,3 Temp
    // 7/28/1995,Russian,1:10:00 PM,1:30:00 PM,106 Wellman
    // ECS 30-C,11:00:00 AM,11:50:00 AM,3 Temp
    std::string subjectStr, locationStr;
    std::getline(is, subjectStr, ',');
    appt.subject = new char[strlen(subjectStr.c_str()) + 1];
    strcpy(appt.subject, subjectStr.c_str());

    is >> appt.startTime;
    is >> appt.endTime;

    std::getline(is, locationStr);
    appt.location = new char[strlen(locationStr.c_str()) + 1];
    strcpy(appt.location, locationStr.c_str());
    
    return is;
}

std::ostream & operator<<(std::ostream &os, const Appointment &appt)
{
    os << appt.startTime
        << " " << appt.endTime << " " 
        << std::left << std::setfill(' ') << std::setw(13) << appt.subject 
        << " " << appt.location << "\n";
    return os;

}


Appointment::~Appointment()
{
    delete[] subject;
    delete[] location;
}
