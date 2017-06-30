#ifndef TIME_H
#define TIME_H

#include <cstring>
#include <cstdlib>

typedef struct {
    short hour;
    short minute;
} Time;

bool lessThan(Time t1, Time t2);

void print(Time t);

void read(Time *t);

#endif
