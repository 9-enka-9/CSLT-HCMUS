// Tran Thi Minh Anh 26120019
#include<iostream>
using namespace std;

int main (){
    int regisNum;
    cout<<"Registration number = "; cin>>regisNum;
    int score=0;
    while (regisNum>0){
        score += regisNum%10;
        regisNum/=10;
    }
    cout<<"Lucky number = "<<score%10;
}