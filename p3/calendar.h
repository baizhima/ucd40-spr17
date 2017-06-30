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
  void readFile();
  void dateSearch() const;
  void subjectSearch() const;
  void destroy();
  void resize();
}; // class Calendar


#endif
