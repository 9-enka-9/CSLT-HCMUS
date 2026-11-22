// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    float a,b,c;
    cout<<"Enter 3 positive real numbers = ";
    cin>>a>>b>>c;
    while (a<0 or b<0 or c<0){
        cout<<"Enter 3 positive real numbers = ";
        cin>>a>>b>>c;       
    }
    
    if (a+b<=c or a+c<=b or c+b<=a){
        cout<<"Cannot form a triangle!";
        return 0;
    } else cout<<"Can form a triangle.\n";
    
    if (abs(a-b)<1e-6 and abs(b-c)<1e-6){
        cout<<"Equilateral triangle.";
    } else if (abs(a-b)<1e-6 or abs(b-c)<1e-6 or abs(a-c)<1e-6){
        if (abs(a*a + b*b - c*c)<1e-6 
        or abs(b*b + c*c - a*a)<1e-6 
        or abs(a*a + c*c - b*b)<1e-6){
            cout<<"Right-isosceles triangle.\n";
        } else {
            cout<<"Isosceles.";
        } 
    } else if (abs(a*a + b*b - c*c)<1e-6 or abs(b*b + c*c - a*a)<1e-6 
    or abs(a*a + c*c - b*b)<1e-6){
            cout<<"Right triangle.\n";
    } else cout<<"Normal triangle.\n";
}