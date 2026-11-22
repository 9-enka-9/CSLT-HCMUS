#include <iostream>
using namespace std;

long long giaithua(long long n);
long long giaithua(long long n){
    long long f = 1;
    for(; n > 0; n = n - 1)
        f = f * n;
    return f;
}

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

    fa = giaithua(a);

    fb = giaithua(b);

    fc = giaithua(c);

    S = fa + fb + fc;

    cout << "S: " << S << endl;
    return 1;
}