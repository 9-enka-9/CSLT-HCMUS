#include<bits/stdc++.h>
#include "dates.h"
using namespace std;

void enterDates(int &n, date dates[]){
    cout<<"Enter list of Dates.";
    cout<<"Enter the number of the list = "; cin>>n;
    for (int i=0;i<n;i++){
        cout<<"Enter day month year = ";
        cin>>dates[i].day>>dates[i].month>>dates[i].year;
    }
}

bool comp(date date1, date date2){
    if (date1.year!=date2.year) return date1.year>date2.year;
    else if (date1.month!=date2.month) return date1.month>date2.month;
    else return date1.day>date2.day;
}

void sortDate(int n, date dates[]){
    sort(dates,dates+n,comp);
}

void printDates(int n, date dates[]){
    for (int i=0;i<n;i++){
        cout<<dates[i].day<<"/"<<dates[i].month<<"/"<<dates[i].year<<endl;
    }
}

