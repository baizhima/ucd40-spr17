#ifndef DAY_H
#define DAY_H

#include <cstdlib>

#include "appt.h"

class Day {
    short day;
    short month;
    short year;
    Appointment *appts[8];
    short apptCount;

public:
  void create(int day, int month, int year);
  void destroy();
  bool equal(const Day *that) const;
  bool lessThan(const Day *that) const;
  void read();
  void print() const;
  void subjectSearch(const char *subject) const;

}; // class Day
#endif
