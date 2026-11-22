#include<bits/stdc++.h>
#include "integers.h"
using namespace std;

void enterArray(int &n, int a[]){
    cout<<"Enter N = "; cin>>n;
    for (int i=0;i<n;i++){
        cout<<"Element "<<i<<" = "; cin>>a[i];
    }
}

int countNegative(int n, int a[]){
    int c=0;
    for (int i =0 ;i<n;i++){
        if (a[i]<0) c++;
    }
    return c;
}

bool checkPrime(int n){
    if (n<2) return false;
    for (int i=2;i<=sqrt(n);i++){
        if (n%i==0) return false;
    }
    return true;
}

int countPrime(int n, int a[]){
    int c=0;
    for (int i=0;i<n;i++){
        c+=checkPrime(a[i]);
    }
    return c;
}

 