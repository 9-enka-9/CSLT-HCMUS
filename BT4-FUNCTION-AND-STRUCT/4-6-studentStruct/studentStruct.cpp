// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include "studentStruct.h"

#include <iostream>
#include <iomanip>
using namespace std;

void inputStudent(Student &s) {
    cout << "Enter student ID = ";
    cin >> s.id;
    cin.ignore(); 
    cout << "Enter student name = ";
    getline(cin, s.name);
    cout << "Enter literature point = ";
    cin >> s.literature;
    cout << "Enter math point = ";
    cin >> s.math;
}


float calculateGPA(Student &s) {
    return (s.literature + s.math) / 2.0f;
}


string getRank(float gpa) {
    if (gpa >= 8.5f) return "Excellent";
    if (gpa >= 7.0f) return "Good";
    if (gpa >= 5.0f) return "Fair";
    return "Failed";
}


void printStudentInfo(Student &s) {
    float gpa = calculateGPA(s);
    string rank = getRank(gpa);

    cout << "\nGPA = " << fixed << setprecision(1) << gpa << endl;
    cout << "Rank = " << rank << endl;
}