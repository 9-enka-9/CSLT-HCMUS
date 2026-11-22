#include<bits/stdc++.h>
#include "rotate.h"
using namespace std;
#define MAX 100


int main(){
    int a[MAX][MAX], b[MAX][MAX];
    int m,n;
    
    inputMatrix(n,m,a);
    cout<<"---ORIGINAL MATRIX---\n";
    printMatrix(n,m,a);
    rotateLeft(n,m,a,b);
    cout<<"\nROTATE LEFT\n";
    printMatrix(m,n,b);
    cout<<"\nROTATE RIGHT\n";
    rotateRight(n,m,a,b);
    printMatrix(m,n,b);
}