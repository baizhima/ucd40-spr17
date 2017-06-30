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
  void create();
  Calendar();
  ~Calendar();
  void readFile();
  void dateSearch() const;
  void subjectSearch() const;
  void addAppointment();
  void printAppointmentCount() const;
  void destroy();
  void resize();
private:
  void getDate(int *, int *, int *) const;
  void addAppointmentHelper(Day *);
  char *buildTimeStr() const;
}; // class Calendar


#endif
