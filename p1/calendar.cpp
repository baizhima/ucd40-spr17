#include "calendar.h"

void create(Calendar *cal)
{
    cal->size = 30;
    cal->count = 0;
    cal->days = (Day *) malloc(sizeof(Day) * cal->size);
}

void readFile(Calendar *cal)
{
    FILE *fp = fopen("appts.csv", "r");
    char line[200];
    fgets(line, 200, fp); // title line
    while (fgets(line, 200, fp))
    {
        line[strlen(line)-1] = '\0'; // '\n' -> '\0'
        int month = atoi(strtok(line, "/"));
        int day = atoi(strtok(NULL, "/"));
        int year = atoi(strtok(NULL, ","));
        Day dayTemp;
        create(&dayTemp, day, month, year);
        int idx = 0;
        for (idx = 0; idx < cal->count; idx++)
        {
            if (equal(&dayTemp, &cal->days[idx])) {
                break;
            }
        }
        if (idx == cal->count) { // day not found in calendar
            int pos;
            for (pos = 0; pos < cal->count; pos++) {
               if (lessThan(&dayTemp, &cal->days[pos])) {
                    break;
               }
            }
            for (int i = cal->count-1; i > pos; i--) {
                cal->days[i] = cal->days[i-1];
            }
            cal->days[pos] = dayTemp;
            idx = pos;
            cal->count++;
            if (cal->count == cal->size) {
                resize(cal);
            }
        }
        read(&cal->days[idx]);
    }
    fclose(fp);
}

void dateSearch(Calendar *cal)
{
    bool valid = true;
    char buf[80];
    char line[80];
    int month, day, year;
    while (true)
    {
        if (!valid) {
            printf("%s is not a valid date.\nPlease try again.\n\n", line);
        }
        valid = true;
        printf("Please enter the month, day, and year (mm/dd/yyyy)\n");
        printf(">> ");
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
    printf("Start End   Subject       Location\n");
    Day dayTemp;
    create(&dayTemp, day, month, year);
    for (int i = 0; i < cal->count; i++) {
        if (equal(&dayTemp, &cal->days[i])) {
            print(&cal->days[i]);
        }
    }
    printf("\n");
}

void resize(Calendar *cal)
{
    cal->size = 2 * cal->size;
    cal->days = (Day *) realloc(cal->days, cal->size * sizeof(Day));
}

void subjectSearch(Calendar *cal)
{
    char line[80];
    printf("Please enter the subject >> ");
    fgets(line, 80, stdin);
    line[strlen(line)-1] = '\0';
    printf("Date       Start End   Subject       Location\n");
    for (int i = 0; i < cal->count; i++) {
        subjectSearch(&cal->days[i], line);
    }
    printf("\n");
}

void destroy(Calendar *cal)
{
    for (int i = 0; i < cal->count; i++)
    {
        destroy(&cal->days[i]);
    }
    free(cal->days);
}
