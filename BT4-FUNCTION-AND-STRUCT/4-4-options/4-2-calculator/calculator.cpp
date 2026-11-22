// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include "calculator.h"
#include<iostream>

using namespace std;

void input(int &a, int &b, char &oprt){
    cout<<"Enter two integers = "; 
    cin>>a>>b;
    cout<<"Enter an operator (+, -, *, /, %) = ";
    cin>>oprt;
}

void  sum(int a, int b){
    cout<<(long long)a+(long long)b<<endl;
}

void difference(int a, int b){
    cout<<a-b<<endl;
}

void product(int a, int b){
    cout<<1ll*a*b<<endl;
}

void quotient(int a, int b){
    if (b!=0) cout<<a/b<<endl;
    else {
        cout<<"divided by zero.\n";
    }
}

void remainder(int a, int b){
    if (b!=0) {cout<<a%b;}
    else cout<<"divided by zero.\n";
}

void calculating(int a, int b, char oprt){
    switch (oprt){
        case '+':
            sum(a,b);
            break;
        case '-':
            difference(a,b);
            break;
        case '*':
            product(a,b);
            break;
        case '/':
            quotient(a,b);
            break;
        default:
            remainder(a,b);
    }
}