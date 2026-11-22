// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include<bits/stdc++.h>
using namespace std;

int main(){
    int max, min,a,i=1;
    cout<<"Number "<<i<<" = "; cin>>a;
    max=0;
    while (a<0){
        cout<<"Number "<<i<<" = "; cin>>a; 
    }
    min=a;
    while (a!=0){
        if (min>a) min=a;
        if (max<a) max=a;
        i++;
        cout<<"Number "<<i<<" = "; cin>>a; 
        while (a<0){
            cout<<"Number "<<i<<" = "; cin>>a; 
        }
    }
    cout<<"Max = "<<max<<endl;
    cout<<"Min = "<<min;
} 