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

public:
  void read();
  void print() const;
  bool lessThan(const Appointment *) const;
  void destroy();

}; // class Appointment

#endif
