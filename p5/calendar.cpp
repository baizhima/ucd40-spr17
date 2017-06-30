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



std::istream & operator>>(std::istream &is, Calendar &cal)
{

    std::string line;
    std::getline(is, line, '\n'); // csv header line

    while (is.peek() != EOF)
    {
        std::string mm, dd, yy;

        std::getline(is, mm, '/');
        std::getline(is, dd, '/');
        std::getline(is, yy, ',');

        int month = atoi(mm.c_str());
        int day = atoi(dd.c_str());
        int year = atoi(yy.c_str());
        Day dayTemp(day, month, year);
        cal.addAppointmentHelper(is, &dayTemp);
    }
    return is;
}

void Calendar::addAppointmentHelper(std::istream &is, Day *dayTemp)
{
        int idx = 0;
        for (idx = 0; idx < count; idx++)
        {
            if (*dayTemp == days[idx]) {
                break;
            }
        }
        if (idx == count) { // day not found in calendar
            int pos;
            for (pos = 0; pos < count; pos++) {
               if (*dayTemp < days[pos]) {
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
        is >> days[idx];
}

void Calendar::dateSearch() const
{
    int month = -1, day = -1, year = -1;
    getDate(&month, &day, &year);

    std::cout << "Start End   Subject       Location\n";
    Day dayTemp(day, month, year);
    bool dayFound = false;
    for (int i = 0; i < count; i++) {
        if (dayTemp == days[i]) {
            dayFound = true;
            std::cout << days[i];
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
    ss << subject << "," << startTimeStr << "," << endTimeStr << "," << location;
    std::cout << "ss:[" << ss.str() << "]\n";
    addAppointmentHelper(ss, &dayTemp);

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

    std::string line;
    while (true)
    {
        if (!valid) {
            std::cout << line << " is not a valid date.\nPlease try again.\n\n";
        }
        valid = true;
        std::cout << "\nPlease enter the month, day, and year (mm/dd/yyyy) >> ";

        if (!std::getline(std::cin, line, '/'))
        {
            valid = false;
            continue;
        }
        else
        {
            *month = atoi(line.c_str());
            if (*month < 0 || *month > 12) {
                valid = false;
                continue;
            }
        }
        if (!std::getline(std::cin, line, '/'))
        {
           valid = false;
           continue;
        }
        else
        {
            *day = atoi(line.c_str());
            if (*day < 0 || *day > 31) {
                valid = false;
                continue;
            }
        }
        if (!std::getline(std::cin, line, '\n'))
        {
            valid = false;
            continue;
        }
        else
        {
            *year = atoi(line.c_str());
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
