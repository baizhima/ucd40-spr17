#include "time.h"
#include <cstdio>

bool lessThan(Time t1, Time t2)
{
    if (t1.hour < t2.hour) {
        return true;
    }
    if (t1.hour > t2.hour) {
        return false;
    }
    if (t1.minute < t2.minute) {
        return true;
    }
    return false;

}

void print(Time t)
{
    printf("%02d:%02d", t.hour, t.minute);
}

void read(Time *t)
{

    t->hour = atoi(strtok(NULL, ":"));
    t->minute = atoi(strtok(NULL, ":"));
    strtok(NULL, " ");  // ignore seconds
    char *ptr = strtok(NULL, ","); // before AM or PM
    if (*ptr == 'P' && t->hour < 12)
    {
        t->hour += 12;
    }

}
