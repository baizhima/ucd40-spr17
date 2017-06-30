#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <fstream>
#include "calendar.h"

Calendar::Calendar(): size(30), count(0)
{
    days = new Day[size];
    for (int i = 0; i < size; i++)
    {
        days[i].year = 9999;
    }
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
        Day dayTemp(day, month, year);
        addAppointmentHelper(&dayTemp);
    }
    inf.close();
}

void Calendar::addAppointmentHelper(Day *dayTemp)
{
        int idx = 0;
        for (idx = 0; idx < count; idx++)
        {
            if (dayTemp->equal(&days[idx])) {
                break;
            }
        }
        if (idx == count) { // day not found in calendar
            int pos;
            for (pos = 0; pos < count; pos++) {
               if (dayTemp->lessThan(&days[pos])) {
                    break;
               }
            }
            for (int i = count; i > pos; i--) {
                days[i] = days[i-1];
            }
            days[pos] = *dayTemp;
            idx = pos;
            count++;
            if (count == size) {
                resize();
            }
        }
        days[idx].read();
}

void Calendar::dateSearch() const
{
    int month = -1, day = -1, year = -1;
    getDate(&month, &day, &year);

    std::cout << "Start End   Subject       Location\n";
    Day dayTemp(day, month, year);
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
    delete[] days;
    days = newDays;
}

void Calendar::subjectSearch() const
{
    char *line = new char[80];
    std::cout << "Please enter the subject >> ";
    std::cin.getline(line, 80);
    std::cout << "Date                          Start End   Subject       Location\n";
    for (int i = 0; i < count; i++) {
        days[i].subjectSearch(line);
    }
    std::cout << "\n";
    delete[] line;
}

void Calendar::addAppointment() 
{
    int month, day, year;
    getDate(&month, &day, &year);  
    Day dayTemp(month, day, year);

    char buf[200];
    std::cout << "Subject >> ";
    std::cin.getline(buf, 80);
    char *subject = strdup(buf);

    std::cout << "Location >> ";
    std::cin.getline(buf, 80);
    char *location = strdup(buf);

    std::cout << "Start time (hh:mm) >> ";
    char *startTimeStr = buildTimeStr();

    std::cout << "End time (hh:mm) >> ";
    char *endTimeStr = buildTimeStr();

    std::stringstream ss;
    ss << "1," << subject << "," << startTimeStr << "," << endTimeStr << "," << location;
    strcpy(buf, ss.str().c_str());
    strtok(buf, ",");
    
    addAppointmentHelper(&dayTemp);
    delete[] startTimeStr;
    delete[] endTimeStr;
    delete[] subject;
    delete[] location;
}

char * Calendar::buildTimeStr() const
{
   std::stringstream ss;
   char buf[80];
   std::cin.getline(buf, 80, ':');
   int hh = atoi(buf);
   std::cin.getline(buf, 80, '\n');
   int mm = atoi(buf);
   if (hh >= 12)
   {
       ss << ((hh > 12) ? hh-12 : hh) <<":" << mm << ":00 PM";
   }
   else
   {
        ss << hh << ":" << mm << ":00 AM";
   }
   char *line = new char[ss.str().size()+1];
   strcpy(line, ss.str().c_str());
   return line;
}

void Calendar::printAppointmentCount() const
{
    std::cout << "Appointment count: " << Appointment::count << "\n\n";
}


Calendar::~Calendar()
{
    delete[] days;
}

void Calendar::getDate(int *month, int *day, int *year) const
{
    bool valid = true;
    char buf[80], line[80];

    while (true)
    {
        if (!valid) {
            std::cout << line << " is not a valid date.\nPlease try again.\n\n";
        }
        valid = true;
        std::cout << "\nPlease enter the month, day, and year (mm/dd/yyyy) >> ";
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
            *month = atoi(ptr);
            if (*month < 0 || *month > 12) {
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
            *day = atoi(ptr);
            if (*day < 0 || *day > 31) {
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
            *year = atoi(ptr);
            if (*year < 1990 || *year > 2017) {
                valid = false;
                continue;
            }
        }
        if (valid) {
            break;
        }
    }

}
