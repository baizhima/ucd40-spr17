#ifndef CALENDAR_H
#define CALENDAR_H

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "day.h"

typedef struct {
    Day *days;
    int size;
    int count;

} Calendar;

void create(Calendar *);
void readFile(Calendar *);
void dateSearch(Calendar *);
void subjectSearch(Calendar *);

void destroy(Calendar *);

void resize(Calendar *);

#endif
