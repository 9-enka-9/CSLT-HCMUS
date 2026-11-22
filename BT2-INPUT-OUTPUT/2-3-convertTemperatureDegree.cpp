// Tran Thi Minh Anh 26120019
#include<iostream>
using namespace std;

int main(){
    float celsius, fahrenheit, kelvin;
    cout<<"Celsius = "; cin>>celsius;
    fahrenheit = (celsius * 1.8) + 32;
    kelvin = celsius + 273;

    cout<<"Fahrenheit = "<<fahrenheit<<endl;
    cout<<"Kelvin = "<<kelvin;
    return 0;
}