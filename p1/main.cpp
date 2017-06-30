#include <cstdio>
#include <cstdlib>
#include "calendar.h"

int getChoice()
{
    int choice = -1;
    char buf[80];
    while (true) {
        printf("Calendar Menu\n");
        printf("0. Done\n");
        printf("1. Search for date\n");
        printf("2. Search for object\n\n");
        printf("Your choice >> ");
        fgets(buf, 80, stdin);
        buf[strlen(buf)-1] = '\0';
        choice = atoi(buf);
        if (choice < 0 || choice > 2) {
            printf("%d is not a valid choice.\nPlease try again.\n\n", choice);
        }
        else {
            return choice;
        }
    }
}

int main()
{
    int choice;
    Calendar cal;
    create(&cal);
    readFile(&cal);
    while ((choice = getChoice())) {
        switch (choice) {
            case 1: dateSearch(&cal); break;
            case 2: subjectSearch(&cal); break;
            default: printf("choice=%d,should not be here\n", choice);
        }
    }
    destroy(&cal);
    return 0;
}
