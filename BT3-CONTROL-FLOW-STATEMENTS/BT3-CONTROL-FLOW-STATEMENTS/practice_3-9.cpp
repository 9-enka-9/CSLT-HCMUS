// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n=-1;
    while (n<=0) {
        cout<<"Enter a positive integer: ";
        cin>>n;
    }
    int count=1;
    for (int i=2;i<=n;i++){
        bool check=true;
        for (int j=2;j<=sqrt(i);j++){
            if (i%j==0) {
                check=false;
                break;
            }
        }
        if (check){
            cout<<"#"<<count<<" = "<<i<<endl;
            count++;
        }
    }
    cout<<"There are "<<count-1<<" prime numbers.";
}