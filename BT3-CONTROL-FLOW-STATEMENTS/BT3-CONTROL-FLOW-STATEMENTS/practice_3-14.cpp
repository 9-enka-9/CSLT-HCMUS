// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int month, year, startDay;

    do {
        cout << "Month and year to view calendar? ";
        cin >> month >> year;
    } while (month < 1 || month > 12 || year < 1);

    do {
        cout << "Day of week of first day in month? ";
        cin >> startDay;
    } while (startDay < 1 || startDay > 7);

    int daysInMonth = 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        daysInMonth = 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else if (month == 2) {
        bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        if (isLeap) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    }

    cout << endl;

    cout << " Mon Tue Wed Thu Fri Sat Sun" << endl;

    if (startDay==1){
        startDay==7;
    } else startDay--;
    
    for (int i = 1; i < startDay; i++) {
        cout << "    ";
    }

    int currentDayOfWeek = startDay;

    for (int day = 1; day <= daysInMonth; day++) {
        cout << setw(4) << day;

        if (currentDayOfWeek == 7) {
            cout << endl;
            currentDayOfWeek = 1;
        } else {
            currentDayOfWeek++;
        }
    }
    
    if (currentDayOfWeek != 1) {
        cout << endl;
    }

    return 0;
}