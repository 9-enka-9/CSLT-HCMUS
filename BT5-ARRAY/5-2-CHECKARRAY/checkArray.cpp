#include<bits/stdc++.h>
#include "checkArray.h"
using namespace std;

void enterArray(int &n, int a[]){
    cout<<"Enter N = ";
    cin>>n;
    cout<<"Enter elements: ";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
}

bool ascendOrder(int n,int a[]){
    for (int i=0;i<n-1;i++){
        if (a[i]>a[i+1]) return false;
    }
    return true;
}

bool symmetric(int n, int a[]){
    for (int i=0;i<n/2;i++){
        if (a[i] != a[n-i-1]) return false;
    }
    return true;
}

bool arithmetic(int n, int a[]){
    int d = a[1]-a[0];
    for (int i=1;i<n-1;i++){
        if (a[i+1]-a[i]!=d) return false;
    }
    return true;
}
