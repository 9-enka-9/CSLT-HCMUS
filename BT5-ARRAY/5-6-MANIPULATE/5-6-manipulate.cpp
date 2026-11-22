#include<bits/stdc++.h>
#include "manipulate.h"
using namespace std;
#define MAX 100

int main() {
    int A[MAX][MAX];
    int M, N;

    inputMatrix(A, M, N);
    printMatrix(A, M, N);
    findSpecialElements(A, M, N);

    return 0;
}