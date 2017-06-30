#ifndef APPT_H
#define APPT_H

#include "time.h"

#include <cstring>
#include <cstdlib>
#include <iostream>

class Appointment {
private:
    Time startTime;
    Time endTime;
    char *subject;
    char *location;
public:
    static int count;

public:
  Appointment();
  Appointment(const Appointment &);
  ~Appointment();
  virtual Appointment * clone();
  virtual void read(std::istream &);
  friend std::ostream & operator<<(std::ostream &, const Appointment &);
  friend bool operator<(const Appointment &, const Appointment &);
  friend class Day;

  virtual void write(std::ostream &) const;
}; // class Appointment

std::ostream & operator<<(std::ostream &, const Appointment &);
#endif
