#ifndef APPT_H
#define APPT_H

#include "time.h"

#include <cstring>
#include <cstdlib>

class Appointment {
public:
    Time startTime;
    Time endTime;
    char *subject;
    char *location;
    static int count;

public:
  Appointment();
  Appointment(const Appointment &);
  ~Appointment();
  friend std::istream & operator>>(std::istream &, Appointment &);
  friend std::ostream & operator<<(std::ostream &, const Appointment &);
  friend bool operator<(const Appointment &, const Appointment &);
  friend class Day;

}; // class Appointment


#endif
