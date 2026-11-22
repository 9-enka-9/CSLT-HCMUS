#include<bits/stdc++.h>
#include "integers.h"
using namespace std;
#define MAX 1000

int main(){
    int n;
    int a[MAX];
    enterArray(n,a);
    cout<<"Negative numbers: "<<countNegative(n,a)<<"."<<endl;
    cout<<"Prime numbers: "<<countPrime(n,a)<<".";
}