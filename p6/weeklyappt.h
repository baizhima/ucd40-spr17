#ifndef WEEKLYAPPT_H
#define WEEKLYAPPT_H

#include "appt.h"

class WeeklyAppointment: public Appointment {
public:
    WeeklyAppointment();
    WeeklyAppointment(const WeeklyAppointment &);
    virtual Appointment * clone();
    virtual void read(std::istream &);
    virtual void write(std::ostream &) const;
    const char *getSeries() const  { return series; } 
    int getSeriesCount() const { return seriesCount; }
private:
    char series[8];
    int seriesCount;
};

#endif
