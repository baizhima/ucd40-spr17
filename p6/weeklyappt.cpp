
#include "weeklyappt.h"
#include <iostream>
#include <iomanip>
#include <cstring>

WeeklyAppointment::WeeklyAppointment(): Appointment(), seriesCount(0)
{
    memset(series, 0, sizeof(char) * 8);
    seriesCount = 0;    
}

WeeklyAppointment::WeeklyAppointment(const WeeklyAppointment &that): Appointment(that)
{
   strcpy(series, that.series);
   seriesCount = that.seriesCount;
}

Appointment * WeeklyAppointment::clone()
{
    Appointment *newAppt = new WeeklyAppointment(*this);
    return newAppt;
}

void WeeklyAppointment::read(std::istream &is)
{
    /*
     *
     * Date,Class,Subject,Start Time,End Time,Location,Series,Count
     * 8/8/2012,1,Psychiatry,10:10:00 AM,12:50:00 PM,6 Olson,WF,10
     * 3/9/2004,0,Psychiatry,9:00:00 AM,10:45:00 AM,1003 Geidt,,
     * 1/21/2000,0,German,6:10:00 AM,8:55:00 AM,1100 Social Science,,
     * 1/17/1995,0,Linguistics,5:50:00 PM,7:00:00 PM,1003 Geidt,,
    */
    Appointment::read(is);
    /* std::istream & is
     * WF,10
     */
    
    std::string token;
    std::getline(is, token, ',');
    strcpy(series, token.c_str());

    std::getline(is, token);
    seriesCount = atoi(token.c_str());
}

void WeeklyAppointment::write(std::ostream &os) const
{
    Appointment::write(os);
    os << std::setw(7) << series << "(" << seriesCount << ")";
}

