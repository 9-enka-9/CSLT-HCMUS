// Tran Thi Minh Anh 26120019
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double p,q;
    cout<<"Enter p, q = "; cin>>p>>q;
    double same=sqrt((pow(p,6)/27) + (q*q/4));
    double res = cbrt(same - q/2) - cbrt(same + q/2);
    cout<<"Solution x = "<<fixed<<setprecision(6)<<res;
}