#ifndef TIME_H
#define TIME_H

#include <cstring>
#include <cstdlib>
#include <iostream>

class Time {
  short hour;
  short minute;

public:
  friend std::ostream& operator<<(std::ostream &, const Time &);
  friend std::istream & operator>>(std::istream &, Time &);
  friend bool operator<(const Time &t1, const Time &t2);
}; // class Time

#endif
