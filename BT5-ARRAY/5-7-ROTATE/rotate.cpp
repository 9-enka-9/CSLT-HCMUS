#include<bits/stdc++.h>
#include "rotate.h"
using namespace std;
#define MAX 100

void inputMatrix(int &n, int &m, int a[][MAX]){
    cout<<"Enter number of rows and columns: "; cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
}

void rotateLeft(int n, int m, int a[][MAX], int b[][MAX]){
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            b[r][c] = a[c][m - 1 - r];
        }
    }
}

void rotateRight(int n, int m, int a[][MAX], int b[][MAX]){
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            b[r][c] = a[n - 1 - c][r];
        }
    }
}

void printMatrix(int row, int col, int arr[][MAX]){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}