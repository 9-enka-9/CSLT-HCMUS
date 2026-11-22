#include<bits/stdc++.h>
#include "checkArray.h"
using namespace std;
#define MAX 1000 

int main(){
    int n;
    int a[MAX];
    
    cout<<"Check if:\na) Array is in ascending order.\nb) Array is symmetric.\nc) Array is an arithmetic progression.\n";
    enterArray(n,a);
    if (ascendOrder(n,a)){
        cout<<"Array is ascending.";
    } else cout<<"Array is not ascending.";
    cout<<endl;
    if (symmetric(n,a)){
        cout<<"Array is symmetric.";
    } else cout<<"Array is not symmetric.";
    cout<<endl;
    if (arithmetic(n,a)){
        cout<<"Array is an arithmetic progression.";
    } else cout<<"Array is not an arithmetic progression.";
}







