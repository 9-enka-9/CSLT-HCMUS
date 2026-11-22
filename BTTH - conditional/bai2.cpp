#include<bits/stdc++.h>
using namespace std;

int days_in_month(int month, int year){
    int days;
    // TODO
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        days=31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days=30;
    } else if (month == 2) {
        bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        if (isLeap) {
            days=29;
        } else {
            days=28;
        }
    }
    // END TODO
    return days;
}


bool is_valid(int day, int month, int year){
    // TODO
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day <=31 and day>=1) return true;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day<30 and day>1) return true;
    } else if (month == 2) {
        bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        if (isLeap) {
            if (day<=29 and day>=1) return true;
        } else {
            if ( day<=28 and day>=1) return true;
        }
    }
    // END TODO
    return false;
}

int main(){
    int day, month, year;
    cin>>day>>month>>year;
    int valid = 0;
    int prev_day = 1, prev_month = 1, prev_year = 1;
    int next_day = 1, next_month = 1, next_year = 1;
    // TODO
    valid = is_valid(day,month,year);
    if (valid){
        if (day==1){
            bool befyear=(month-1==0);
            prev_day = days_in_month(month-1,year)*(!befyear) + (befyear)*days_in_month(12,year-1);
            if (befyear){
                prev_month=12;
                prev_year=year-1;
            } else {
                prev_month=month-1;
                prev_year=year;
            }
            next_day=day+1;
            next_month=month;
            next_year=year;
        } else if (day==days_in_month(month,year)){
            prev_day=day-1;
            prev_month=month;
            prev_year=year;
            if (month ==12){
                next_day=1;
                next_month=1;
                next_year=year+1;
            } else {
                next_day=1;
                next_month=month+1;
                next_year=year; 
            }
        } else {
            next_day=day+1;
            next_month=month;
            next_year=year;
            prev_day=day-1;
            prev_month=month;
            prev_year=year;
        }
    }
    
    // cout<<is_valid<<endl;
    // cout<<prev_day<<" "<<prev_month<<" "<<prev_year<<endl;
    // cout<<next_day<<" "<<next_month<<" "<<next_year;
    
    // END TODO
    // return {
    //     valid,
    //     {prev_day, prev_month, prev_year},
    //     {next_day, next_month, next_year}
    // };
}