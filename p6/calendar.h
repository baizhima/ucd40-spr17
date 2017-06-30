#ifndef CALENDAR_H
#define CALENDAR_H

#include <cstdlib>
#include <cstring>
#include "day.h"
#include "vector.h"


class Calendar {

  Vector<Day> days;

public:
  Calendar();
  ~Calendar();
  friend std::istream & operator>>(std::istream &, Calendar &);
  void dateSearch() const;
  void subjectSearch() const;
  void addAppointment();
  void printAppointmentCount() const;
private:
  void getDate(int *, int *, int *) const;
  void addAppointmentHelper(std::istream &, Day *);
  void createSeries(WeeklyAppointment appt, int day, int month, int year);
  char *buildTimeStr() const;
}; // class Calendar


#endif
