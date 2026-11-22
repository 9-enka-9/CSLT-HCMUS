#include<bits/stdc++.h>
#include "matrix.h"
using namespace std;


void enterMatrix(int &n, int a[][100]){
    cout<<"--MATRIX--"<<endl;
    cout<<"Enter N = "; cin>>n;
    for (int i =0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
}

int mainDiagonal(int n, int a[][100]){
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=a[i][i];
    }
    return sum;
}

int antiDiagonal(int n, int a[][100]){
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=a[i][n-i-1];
    }
    return sum;
}

bool isMagic(int n, int a[][100]){
    int sum1=0;
    for (int i=0;i<n;i++){
        sum1+=a[0][i];
    }
    
    for(int i=0;i<n;i++){
        int sumt=0;
        for (int j=0;j<n;j++){
            sumt+=a[i][j];
        }
        if (sum1!=sumt) return false;
    }
    
    for(int i=0;i<n;i++){
        int sumt=0;
        for (int j=0;j<n;j++){
            sumt+=a[j][i];
        }
        if (sum1!=sumt) return false;
    }
    return true;
}   