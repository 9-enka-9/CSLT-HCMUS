#ifndef STUDENTS_H
#define STUDENTS_H
#include<string>

struct Student{
    std::string id;
    std::string name;
    double gpa;
    
    bool operator< (const Student other){
        return  gpa<other.gpa;
    }
    
    bool operator<= (const Student other){
        return gpa<=other.gpa;
    }
    
};

void enterListStudents(int &n, Student students[]);

void listInDescending(int n, Student students[]);

#endif