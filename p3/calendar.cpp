#include <iostream>
#include <iomanip>
#include <fstream>
#include "calendar.h"

void Calendar::create()
{
    size = 30;
    count = 0;
    days = new Day[size];
}

void Calendar::readFile()
{
    std::ifstream inf("appts.csv");

    char line[200];
    inf.getline(line, 200);
    while (inf.getline(line, 200))
    {
        int month = atoi(strtok(line, "/"));
        int day = atoi(strtok(NULL, "/"));
        int year = atoi(strtok(NULL, ","));
        Day dayTemp;
        dayTemp.create(day, month, year);
        int idx = 0;
        for (idx = 0; idx < count; idx++)
        {
            if (dayTemp.equal(&days[idx])) {
                break;
            }
        }
        if (idx == count) { // day not found in calendar
            int pos;
            for (pos = 0; pos < count; pos++) {
               if (dayTemp.lessThan(&days[pos])) {
                    break;
               }
            }
            for (int i = count-1; i > pos; i--) {
                days[i] = days[i-1];
            }
            days[pos] = dayTemp;
            idx = pos;
            count++;
            if (count == size) {
                resize();
            }
        }
        days[idx].read();
    }
    inf.close();
}

void Calendar::dateSearch() const
{
    bool valid = true;
    char buf[80];
    char line[80];
    int month, day, year;
    while (true)
    {
        if (!valid) {
            std::cout << line << " is not a valid date.\nPlease try again.\n\n";
        }
        valid = true;
        std::cout << "Please enter the month, day, and year (mm/dd/yyyy)\n>> ";
        fgets(buf, 80, stdin);
        buf[strlen(buf)-1] = '\0'; // trailing '\n'
        strcpy(line, buf);
        char *ptr = NULL;
        if ((ptr = strtok(buf, "/")) == NULL)
        {
            valid = false;
            continue;
        }
        else
        {
            month = atoi(ptr);
            if (month < 0 || month > 12) {
                valid = false;
                continue;
            }
        }
        if ((ptr = strtok(NULL, "/")) == NULL)
        {
           valid = false;
           continue;
        }
        else
        {
            day = atoi(ptr);
            if (day < 0 || day > 31) {
                valid = false;
                continue;
            }
        }
        if ((ptr = strtok(NULL, "/")) == NULL)
        {
            valid = false;
            continue;
        }
        else
        {
            year = atoi(ptr);
            if (year < 2000 || year > 2017) {
                valid = false;
                continue;
            }
        }
        if (valid) {
            break;
        }
    }
    std::cout << "Start End   Subject       Location\n";
    Day dayTemp;
    dayTemp.create(day, month, year);
    for (int i = 0; i < count; i++) {
        if (dayTemp.equal(&days[i])) {
            days[i].print();
        }
    }
    std::cout << "\n";
}

void Calendar::resize()
{
    Day *newDays = new Day[2 * size];
    for (int i = 0; i < size; i++) {
        newDays[i] = days[i];
    }
    size *= 2;
    days = newDays;
}

void Calendar::subjectSearch() const
{
    char line[80];
    std::cout << "Please enter the subject >> ";
    std::cin.getline(line, 80);

    std::cout << "Date       Start End   Subject       Location\n";
    for (int i = 0; i < count; i++) {
        days[i].subjectSearch(line);
    }
    std::cout << "\n";
}

void Calendar::destroy()
{
    for (int i = 0; i < count; i++)
    {
        days[i].destroy();
    }
    delete[] days;
}
