#ifndef DATES_H
#define DATES_H

struct date{
    int day,month,year;
    
};

void enterDates(int &n, date dates[]);

void sortDate(int n, date dates[]);

bool comp(date date1, date date2);

void printDates(int n, date dates[]);

#endif