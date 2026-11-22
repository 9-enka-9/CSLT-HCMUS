// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include "options.h"
#include "4-2-calculator/calculator.h"
#include "4-3-triangle/triangle.h"
#include<iostream>
using namespace std;

int main(){
    int option;
    do{
        inputOption(option);
        if (option==2){
            double a,b,c;
            inputTri(a,b,c);
            if (checkTri(a,b,c)){
                cout<<"Can form a triangle.\n";
                triType(a,b,c);
            } else cout<<"Cannot form a triangle!\n";
        } else if (option==1){
            int a,b;
            char oprt;
            input(a,b,oprt);
            calculating(a,b,oprt);
        }
    } while (option!=3);
    cout<<"Exit program.";
}