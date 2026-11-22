// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
#include<iostream>
using namespace std;

int main(){
    int oldkwh=0,newkwh=-1; 
    while (newkwh - oldkwh<0){
        cout<<"Enter old and new kWh: ";
        cin>>oldkwh>>newkwh;
    }
    int kwh=newkwh-oldkwh;
    int bill=0;
    if (kwh<50){
        bill+=1984*kwh;
    } else if (kwh<100){
        bill+=1984*50;
        bill+=(kwh-50)*2050;
    } else if (kwh<200){
        bill+=1984*50;
        bill+=50*2050;
        bill+=(kwh-100)*2380;
    } else if (kwh<300){
        bill+=1984*50;
        bill+=50*2050;
        bill+=100*2380;
        bill+=(kwh-200)*2998;
    } else if (kwh<400){
        bill+=1984*50;
        bill+=50*2050;
        bill+=100*2380;
        bill+=100*2998;   
        bill+=(kwh-300)*3350;
    } else {
        bill+=1984*50;
        bill+=50*2050;
        bill+=100*2380;
        bill+=100*2998;   
        bill+=100*3350;
        bill+=(kwh-400)*3460;
    }
    cout<<"Price: "<<bill;
}