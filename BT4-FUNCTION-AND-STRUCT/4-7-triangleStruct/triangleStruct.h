// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn
 
#ifndef TRIANGLESTRUCT_H
#define TRIANGLESTRUCT_H


#include <string>
using namespace std;

struct Point {
    double x;
    double y;
};

struct Triangle {
    Point A;
    Point B;
    Point C;
};

void inputPoint(Point &p, string name);
void inputTriangle(Triangle &t);
double distance(Point p1, Point p2);
double calculatePerimeter(Triangle &t);
Point findCentroid(Triangle &t);
void printTriangleInfo(Triangle &t);

#endif