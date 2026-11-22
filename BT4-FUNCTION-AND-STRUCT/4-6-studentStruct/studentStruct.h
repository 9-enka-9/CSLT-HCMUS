// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#ifndef STUDENTSTRUCT_H
#define STUDENTSTRUCT_H
#include<string>
using namespace std;

struct Student{
    string id;
    string name;
    float literature;
    float math;
};

void inputStudent(Student &s);
float calculateGPA(Student &s);
string getRank(float gpa);
void printStudentInfo(Student &s);

#endif