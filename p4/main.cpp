#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "calendar.h"

int getChoice()
{
    int choice = -1;
    char buf[80];
    while (true) {
        std::cout << "Calendar Menu" << std::endl;
        
        std::cout << "0. Done.\n";
        std::cout << "1. Search for date.\n";
        std::cout << "2. Search for subject.\n";
        std::cout << "3. Add an appointment.\n";
        std::cout << "4. Print appointment count.\n\n";
        std::cout << "Your choice >> ";
        std::cin.getline(buf, 80);
        choice = atoi(buf);
        if (choice < 0 || choice > 4) {
            std::cout << choice << " is not a valid choice.\nPlease try again.\n\n";
        }
        else {
            return choice;
        }
    }
    return choice;
}

int main()
{
    int choice;
    Calendar cal;
    cal.readFile();
    while ((choice = getChoice())) {
        switch (choice) {
            case 1: cal.dateSearch(); break;
            case 2: cal.subjectSearch(); break;
            case 3: cal.addAppointment(); break;
            case 4: cal.printAppointmentCount(); break;
            default: std::cout << "should not be here\n";
        }
    }
    return 0;
}
