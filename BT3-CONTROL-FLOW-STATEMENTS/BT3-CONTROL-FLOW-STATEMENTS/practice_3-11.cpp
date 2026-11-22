// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter N, M = ";
    cin>>n>>m;
    cout<<"The first 3 bit from the right of "<<n<<": ";
    //Claude
    for (int i = m - 1; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
}