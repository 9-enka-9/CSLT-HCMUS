// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include "triangle.h"
#include<iostream>
using namespace std;

int main(){
    double a,b,c;
    input(a,b,c);
    if (checkTri(a,b,c)){
        cout<<"Can form a triangle.\n";
        triType(a,b,c);
    } else cout<<"Cannot form a triangle!\n";
    return 0;
}