#include<bits/stdc++.h>
#include "students.h"
using namespace std;

void enterListStudents(int &n, Student students[]){
    cout<<"Enter number of students: "; cin>>n;
    cout<<"Enter students: \n";
    for (int i=0;i<n;i++){
        cout<<"Enter id: "; cin>>students[i].id;
        cout<<"Enter name: "; 
        cin.ignore();
        getline(cin,students[i].name);
        cout<<"Enter gpa: "; cin>>students[i].gpa;
    }
}

bool comp(Student st1,Student st2){
    return st1.gpa>st2.gpa;
}

void listInDescending(int n, Student students[]){
    sort(students,students+n, comp);
    for (int i=0;i<n;i++){
        cout<<"Name: "<<students[i].name<<endl;
        cout<<"ID: "<<students[i].id<<endl;
        cout<<"GPA: "<<students[i].gpa<<endl;
        cout<<endl;
    }
}