#include <iostream>
using namespace std;

int main(){
    long long S = 0;
    long long a, b, c;
    long long fa, fb, fc;

    cout << "Chuong trinh tinh S = a! + b! + c!" << endl;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;

    fa = 1;
    for(; a > 0; a = a - 1)
        fa = fa * a;

    fb = 1;
    for(; b > 0; b = b - 1)
        fb = fb * b;

    fc = 1;
    for(; c > 0; c = c - 1)
        fc = fc * c;

    S = fa + fb + fc;

    cout << "S: " << S << endl;
    return 1;
}