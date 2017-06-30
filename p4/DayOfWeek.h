
#ifndef DAYOFWEEK_H
#define DAYOFWEEK_H

class DayOfWeek {
    char monthName[10];
    int month;
    int day;
    int year;
    char dayName[10];
public:
    DayOfWeek();
    ~DayOfWeek();
    void read(int month, int day, int year);

    void print();

};

#endif
