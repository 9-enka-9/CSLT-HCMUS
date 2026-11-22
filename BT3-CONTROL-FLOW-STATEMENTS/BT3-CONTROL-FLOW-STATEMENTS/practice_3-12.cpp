// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include<iostream>
using namespace std;

int main(){
    long long phoneNum=LONG_LONG_MAX;
    while (phoneNum>9999999999 or phoneNum<0){
        cout<<"Phone number: ";
        cin>>phoneNum;
    }
    long long copy=0;
    while (phoneNum!=0){
        copy*=10;
        copy+=(phoneNum%10);
        phoneNum/=10;
    }
    while (copy!=0){
        int t=copy%10;
        copy/=10;
        switch (t){
            case 1:
                cout<<"one ";
                break;
            case 2:
                cout<<"two ";
                break;
            case 3:
                cout<<"three ";
                break;
            case 4:
                cout<<"four ";
                break;
            case 5:
                cout<<"five ";
                break;
            case 6:
                cout<<"six ";
                break;
            case 7:
                cout<<"seven ";
                break;
            case 8:
                cout<<"eight ";
                break;
            case 9:
                cout<<"nine ";
                break;
            default:
                cout<<"zero";
        }
    }
}