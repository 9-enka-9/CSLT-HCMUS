// Tran Thi Minh Anh 26120019
#include<iostream>
using namespace std;

int main() {
    int h1,m1,s1,h2,m2,s2;
    cout<<"T1 (h m s) = "; cin>>h1>>m1>>s1;
    cout<<"T2 (h m s) = "; cin>>h2>>m2>>s2;

    int distance = (h2-h1)*60*60 + (m2-m1)*60 + (s2-s1);
    cout<<"Distance = "<<distance;
    return 0;
}