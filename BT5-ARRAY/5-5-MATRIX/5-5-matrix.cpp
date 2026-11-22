#include<bits/stdc++.h>
#include "matrix.h"
using namespace std;

int main(){
    int n;
    int a[100][100];
    enterMatrix(n,a);
    cout<<"Main diagonal = "<< mainDiagonal(n,a)<<".\n";
    cout<<"Anti-diagonal = "<<antiDiagonal(n,a)<<".\n";
    if (isMagic(n,a)) cout<<"It is a magic square.";
    else cout<<"It is not a magic square.";
}