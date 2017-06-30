#ifndef TIME_H
#define TIME_H

#include <cstring>
#include <cstdlib>

class Time {
  short hour;
  short minute;

public:
  bool lessThan(const Time *t2) const;
  void print() const;
  void read();
}; // class Time

#endif
