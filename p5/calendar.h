#ifndef CALENDAR_H
#define CALENDAR_H

#include <cstdlib>
#include <cstring>
#include "day.h"

class Calendar {

  Day *days;
  int size;
  int count;

public:
  Calendar();
  ~Calendar();
  friend std::istream & operator>>(std::istream &, Calendar &);
  void dateSearch() const;
  void subjectSearch() const;
  void addAppointment();
  void printAppointmentCount() const;
  void resize();
private:
  void getDate(int *, int *, int *) const;
  void addAppointmentHelper(std::istream &, Day *);
  char *buildTimeStr() const;
}; // class Calendar


#endif
