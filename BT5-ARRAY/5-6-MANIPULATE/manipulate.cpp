#include<bits/stdc++.h>
#include "manipulate.h"
#include <iostream>
using namespace std;
#define MAX 100


void inputMatrix(int A[][MAX], int &M, int &N) {
    cout << "Enter rows (M) and columns (N): ";
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
}

void printMatrix(int A[][MAX], int M, int N) {
    cout << "\n--- Matrix (" << M << "x" << N << ") ---\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << "\t";
        }
        cout << "\n";
    }
}

int sumRow(int A[][MAX], int N, int r) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
        sum += A[r][j];
    }
    return sum;
}

int sumCol(int A[][MAX], int M, int c) {
    int sum = 0;
    for (int i = 0; i < M; i++) {
        sum += A[i][c];
    }
    return sum;
}

void findSpecialElements(int A[][MAX], int M, int N) {
    cout << "\nElements equal to sum of remaining elements on its row and column:\n";
    bool found = false;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int rowRemaining = sumRow(A, N, i) - A[i][j];

            int colRemaining = sumCol(A, M, j) - A[i][j];

            if (A[i][j] == rowRemaining + colRemaining) {
                cout << "A[" << i << "][" << j << "] = " << A[i][j] 
                          << " (Row remaining sum = " << rowRemaining 
                          << ", Col remaining sum = " << colRemaining << ")\n";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No matching element found.\n";
    }
}