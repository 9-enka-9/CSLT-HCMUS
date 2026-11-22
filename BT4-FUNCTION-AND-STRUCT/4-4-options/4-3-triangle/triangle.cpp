// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include "triangle.h"
#include<iostream>
#include<cmath>
using namespace std;

void inputTri(double &a, double &b, double &c){
    do{
        cout<<"Enter 3 positive real numbers = ";
        cin>>a>>b>>c;
    } while (a<=0 or b<=0 or c<=0);
}

bool checkTri(double a, double b, double c){
    if (a+b<=c or a+c<=b or c+b<=a){
        return false;
    }
    return true;
}

void triType(double a, double b, double c){
    if (abs(a-b)<1e-6 and abs(b-c)<1e-6){
        cout<<"Equilateral triangle.";
    } else if (abs(a-b)<1e-6 or abs(b-c)<1e-6 or abs(a-c)<1e-6){
        if (abs(a*a+b*b-c*c)<1e-6 or abs(a*a+c*c-b*b)<1e-6 or abs(b*b+c*c-a*a)<1e-6){
            cout<<"Right-isosceles triangle.";
        } else cout<<"Isoscesles triangle.";
    } else if (abs(a*a+b*b-c*c)<1e-6 or abs(a*a+c*c-b*b)<1e-6 or abs(b*b+c*c-a*a)<1e-6){
        cout<<"Right triangle.";
    } else cout<<"Normal triangle.";
    cout<<endl;
}
