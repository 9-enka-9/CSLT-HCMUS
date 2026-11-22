// Tran Thi Minh Anh 26120019
#include<iostream>
using namespace std;

int main() {
    string name; int year;
    cout<<"Name = "; getline(cin, name);
    cout<<"Birth-year = "; cin>>year;
    cout<<"Hello " << name << ", now you are " << 2024 - year << " years old.";
}