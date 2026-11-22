// Tran Thi Minh Anh 26120019
#include<iostream>
using namespace std;

int main(){
    int amount;
    cout<<"Exchange money = "; cin>>amount;
    if (amount/20000>0){
        cout<<"Note 20000: "<<amount/20000<<endl;
        amount -= (amount/20000)*20000;
    } else cout<<"Note 20000: 0"<<endl;
    if (amount/10000>0){
        cout<<"Note 10000: "<<amount/10000<<endl;
        amount -= (amount/10000)*10000;
    } else cout<<"Note 10000: 0"<<endl;
    if (amount/5000>0){
        cout<<"Note  5000: "<<amount/5000<<endl;
        amount -= (amount/5000)*5000;
    } else cout<<"Note  5000: 0"<<endl;
    if (amount/1000>0){
        cout<<"Note  1000: "<<amount/1000<<endl;
        amount -= (amount/1000)*1000;
    } else cout<<"Note  1000: 0"<<endl;
    cout<<"Remain money = "<<amount;
}