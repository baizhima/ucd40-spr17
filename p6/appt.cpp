#include <iostream>
#include <iomanip>
#include "appt.h"

int Appointment::count = 0;

Appointment::Appointment(): subject(NULL), location(NULL)
{
    
}

Appointment::Appointment(const Appointment &rhs): startTime(rhs.startTime), endTime(rhs.endTime),
    subject(new char[strlen(rhs.subject) + 1]), location(new char[strlen(rhs.location) + 1])
{
   strcpy(subject, rhs.subject);
   strcpy(location, rhs.location);
}

Appointment * Appointment::clone()
{
    Appointment *newAppt = new Appointment(*this);
    return newAppt;
}


bool operator<(const Appointment &a1, const Appointment &a2)
{
    return a1.startTime < a2.startTime;
}


void Appointment::read(std::istream &is)
{
    // original appts4.csv line is
    // Date,Class,Subject,Start Time,End Time,Location,Series,Count
    // 8/8/2012,1,Psychiatry,10:10:00 AM,12:50:00 PM,6 Olson,WF,10
    // 3/9/2004,0,Psychiatry,9:00:00 AM,10:45:00 AM,1003 Geidt,,

    // when this func is called, std::istream & is (WeeklyAppointment will not be here)
    // Psychiatry,9:00:00 AM,10:45:00 AM,1003 Geidt,,
    std::string subjectStr, locationStr;
    std::getline(is, subjectStr, ',');
    subject = new char[strlen(subjectStr.c_str()) + 1];
    strcpy(subject, subjectStr.c_str());

    is >> startTime;
    is >> endTime;

    std::getline(is, locationStr, ',');
    location = new char[strlen(locationStr.c_str()) + 1];
    strcpy(location, locationStr.c_str());

}

void Appointment::write(std::ostream &os) const
{
   os << startTime
       << " " << endTime << " "
       << std::left << std::setfill(' ') << std::setw(13) << subject
       << " " << std::setw(26) << location;
}


std::ostream & operator<<(std::ostream &os, const Appointment &appt)
{
    appt.write(os);
    return os;

}


Appointment::~Appointment()
{
    delete[] subject;
    delete[] location;
}
