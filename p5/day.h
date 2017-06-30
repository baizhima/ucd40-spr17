#ifndef DAY_H
#define DAY_H

#include <cstdlib>

#include "appt.h"
#include "linkedlist.h"

class Day {
public:
    short day;
    short month;
    short year;
    LinkedList appts;


public:
  Day();
  Day(int day, int month, int year);
  ~Day();

  friend bool operator<(const Day &, const Day &);
  friend bool operator==(const Day &, const Day &);
  friend std::istream & operator>>(std::istream &, Day &);
  friend std::ostream & operator<<(std::ostream &, const Day &);
  void subjectSearch(const char *subject) const;

public:
  Day & operator=(const Day &);
  Day & operator+=(Appointment *&);

}; // class Day
#endif
