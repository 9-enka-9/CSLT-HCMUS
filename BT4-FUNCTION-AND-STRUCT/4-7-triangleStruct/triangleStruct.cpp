// Sinh vien: Tran Thi Minh Anh
// Lop: 26CTT2
// MSSV: 26120019
// Email: 2612001921@student.hcmus.edu.vn

#include "triangleStruct.h"
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

 
void inputPoint(Point &p, string name) {
    cout << "Enter point " << name << " (x y) = ";
    cin >> p.x >> p.y;
}

void inputTriangle(Triangle &t) {
    cout << "--- Enter Triangle Points ---\n";
    inputPoint(t.A, "A");
    inputPoint(t.B, "B");
    inputPoint(t.C, "C");
}

double distance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double calculatePerimeter(Triangle &t) {
    double sideAB = distance(t.A, t.B);
    double sideBC = distance(t.B, t.C);
    double sideCA = distance(t.C, t.A);
    return sideAB + sideBC + sideCA;
}

Point findCentroid(Triangle &t) {
    Point G;
    G.x = (t.A.x + t.B.x + t.C.x) / 3.0;
    G.y = (t.A.y + t.B.y + t.C.y) / 3.0;
    return G;
}

void printTriangleInfo(Triangle &t) {
    double perimeter = calculatePerimeter(t);
    Point centroid = findCentroid(t);

    cout << fixed << setprecision(2);
    cout << "\nPerimeter = " << perimeter << endl;
    cout << "Centroid G = (" << centroid.x << ", " << centroid.y << ")" << endl;
}
