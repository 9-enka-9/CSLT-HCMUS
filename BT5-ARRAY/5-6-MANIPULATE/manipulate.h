#ifndef MANIPULATE_H
#define MANIPULATE_H
#define MAX 100

void inputMatrix(int A[][MAX], int &M, int &N);

void printMatrix(int A[][MAX], int M, int N);

int sumRow(int A[][MAX], int N, int r);

int sumCol(int A[][MAX], int M, int c);

void findSpecialElements(int A[][MAX], int M, int N);

#endif