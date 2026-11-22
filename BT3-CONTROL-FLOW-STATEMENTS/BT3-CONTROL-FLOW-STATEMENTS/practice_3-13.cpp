// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include<iostream>
using namespace std;

int main(){
    long long n=-1;
    while (n<0){
        cout<<"Enter N = ";
        cin>>n;
    }
    if (n==10){
        cout<<"Descending.\n";
        cout<<"Symmetric.";
        return 0;
    }
    long long n1=n/10,t1=n%10,copy=0;
    bool check=true;
    while (n1>0){
        int t2=n1%10;
        if (t1>t2) {
            check=false;
            break;
        }
        t1=t2;
        n1/=10;
    }
    if (check) cout<<"Descending.\n";
    else cout<<"Not descending.\n";
    n1=n;
    while (n1>0){
        copy*=10;
        copy+=(n1%10);
        n1/=10;
    }
    if (n==copy) cout<<"Symmetric.\n";
    else cout<<"Not symmetric.\n";
}