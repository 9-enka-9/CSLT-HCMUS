// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include<iostream>
using namespace std;

int main(){
    int a=-1,b=-1;
    while (a<=0 and b<=0){
        cout<<"Enter 2 positive integers = "; 
        cin>>a>>b;
    }
    int r=1, a1=a,b1=b;
    while (r!=0){
        r=a%b;
        a=b;
        b=r;
    }
    cout<<"GCD = "<<a<<endl;
    int lcm = (a1*b1)/a;
    cout<<"LCM = "<<lcm;
}