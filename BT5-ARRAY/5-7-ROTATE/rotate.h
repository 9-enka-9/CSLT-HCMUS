#ifndef ROTATE_H
#define ROTATE_H
#define MAX 100

void inputMatrix(int &n, int &m, int a[][MAX]);

void rotateLeft(int n, int m, int a[][MAX], int b[][MAX]);

void rotateRight(int n, int m, int a[][MAX], int b[][MAX]);

void printMatrix(int row, int col, int arr[][MAX]);

#endif