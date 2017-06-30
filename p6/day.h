#ifndef DAY_H
#define DAY_H

#include <cstdlib>

#include "appt.h"
#include "weeklyappt.h"
#include "linkedlist.h"

class Day {
public:
    short day;
    short month;
    short year;
    LinkedList<Appointment *> appts;

public:
  Day();
  Day(int day, int month, int year);
  ~Day();

  friend bool operator<(const Day &, const Day &);
  friend bool operator==(const Day &, const Day &);
  friend const Appointment * operator>>(std::istream &, Day &);
  friend std::ostream & operator<<(std::ostream &, const Day &);
  void subjectSearch(const char *subject) const;

public:
  Day & operator=(const Day &);
  Day & operator+=(Appointment *&);
  Day & operator+=(const WeeklyAppointment &);

}; // class Day
#endif
