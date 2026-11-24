#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
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

double distance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double calcPerimeter(const Triangle& t) {
    return distance(t.A, t.B) + distance(t.B, t.C) + distance(t.C, t.A);
}

void printList(const Triangle* a, int n) {
    if (!a || n <= 0) {
        cout << "Danh sach tam giac dang rong!\n";
        return;
    }
    cout << fixed << setprecision(2);
    cout << "\nDanh sach (" << n << " tam giac):\n";
    for (int i = 0; i < n; i++) {
        const Triangle& t = *(a + i);
        cout << "Tam giac [" << i << "]: "
                  << "A(" << t.A.x << ", " << t.A.y << "), "
                  << "B(" << t.B.x << ", " << t.B.y << "), "
                  << "C(" << t.C.x << ", " << t.C.y << ") "
                  << "| Chu vi = " << calcPerimeter(t) << "\n";
    }
}

void inputList(Triangle*& a, int& n) {
    if (a) {
        delete[] a;
        a = nullptr;
    }
    cout << "Nhap so luong tam giac n = ";
    cin >> n;
    if (n <= 0) {
        n = 0;
        return;
    }
    a = new Triangle[n]; 
    for (int i = 0; i < n; i++) {
        cout << "--- Nhap tam giac [" << i << "] ---\n";
        cout << "  Nhap dinh A (x y): "; cin >> (a + i)->A.x >> (a + i)->A.y;
        cout << "  Nhap dinh B (x y): "; cin >> (a + i)->B.x >> (a + i)->B.y;
        cout << "  Nhap dinh C (x y): "; cin >> (a + i)->C.x >> (a + i)->C.y;
    }
}

double findMaxPerimeter(const Triangle* a, int n) {
    double maxP = calcPerimeter(*a);
    for (int i = 1; i < n; i++) {
        double p = calcPerimeter(*(a + i));
        if (p > maxP) {
            maxP = p;
        }
    }
    return maxP;
}

double findMinPerimeter(const Triangle* a, int n) {
    double minP = calcPerimeter(*a);
    for (int i = 1; i < n; i++) {
        double p = calcPerimeter(*(a + i));
        if (p < minP) {
            minP = p;
        }
    }
    return minP;
}

void sortListByPerimeter(Triangle* a, int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double p1 = calcPerimeter(*(a + i));
            double p2 = calcPerimeter(*(a + j));
            if ((ascending && p1 > p2) || (!ascending && p1 < p2)) {
                Triangle temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}

void findPositionsByPerimeter(const Triangle* a, int n, double targetP) {
    bool found = false;
    cout << "Cac vi tri tam giac co chu vi = " << targetP << ": ";
    for (int i = 0; i < n; i++) {
        if (abs(calcPerimeter(*(a + i)) - targetP) < 1e-6) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay!";
    }
    cout << endl;
}

void addTriangle(Triangle*& a, int& n, const Triangle& t, int pos) {
    if (pos < 0 || pos > n) {
        cout << "Vi tri chen khong hop le!\n";
        return;
    }
    Triangle* temp = new Triangle[n + 1];

    for (int i = 0; i < pos; i++) {
        *(temp + i) = *(a + i);
    }
    *(temp + pos) = t;
    for (int i = pos; i < n; i++) {
        *(temp + i + 1) = *(a + i);
    }

    delete[] a;
    a = temp;
    n++;
    cout << "Da them tam giac vao vi tri " << pos << " thanh cong!\n";
}

void inputFromFile(Triangle*& a, int& n, const char* filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Khong the mo file " << filename << " de doc!\n";
        return;
    }
    if (a) {
        delete[] a;
        a = nullptr;
    }
    fin >> n;
    if (n > 0) {
        a = new Triangle[n];
        for (int i = 0; i < n; i++) {
            fin >> (a + i)->A.x >> (a + i)->A.y
                >> (a + i)->B.x >> (a + i)->B.y
                >> (a + i)->C.x >> (a + i)->C.y;
        }
        cout << "Da doc thanh cong " << n << " tam giac tu file " << filename << "!\n";
    } else {
        n = 0;
        cout << "File ranh hoac dinh dang khong hop le!\n";
    }
    fin.close();
}

// 9. Ghi danh sach tam giac ra file text
void outputToFile(const Triangle* a, int n, const char* filename) {
    if (!a || n <= 0) {
        cout << "Danh sach rong, khong the ghi file!\n";
        return;
    }
    ofstream fout(filename);
    if (!fout.is_open()) {
        cout << "Khong the tao/mo file " << filename << " de ghi!\n";
        return;
    }
    fout << n << "\n";
    for (int i = 0; i < n; i++) {
        fout << (a + i)->A.x << " " << (a + i)->A.y << " "
             << (a + i)->B.x << " " << (a + i)->B.y << " "
             << (a + i)->C.x << " " << (a + i)->C.y << "\n";
    }
    fout.close();
    cout << "Da ghi danh sach tam giac ra file " << filename << " thanh cong!\n";
}

int main() {
    Triangle* a = nullptr;
    int n = 0;
    int choice;

    do {
        cout << "\n================= MENU MANAGING TRIANGLES =================";
        cout << "\n1. Print the list";
        cout << "\n2. Input the list";
        cout << "\n3. Find the triangle with maximum perimeter";
        cout << "\n4. Find the triangle with minimum perimeter";
        cout << "\n5. Sort the list by perimeter (1: Ascending / 2: Descending)";
        cout << "\n6. Find positions of Max / Min perimeter triangle";
        cout << "\n7. Add a triangle (at end or any position)";
        cout << "\n8. Input the list from a text file";
        cout << "\n9. Output the list to a text file";
        cout << "\n0. Exit";
        cout << "\n-----------------------------------------------------------";
        cout << "\nSelect choice (0-9): ";
        cin >> choice;

        switch (choice) {
        case 1:
            printList(a, n);
            break;

        case 2:
            inputList(a, n);
            break;

        case 3:
            if (n > 0) cout << "Chu vi Max = " << findMaxPerimeter(a, n) << endl;
            else cout << "Danh sach rong!\n";
            break;

        case 4:
            if (n > 0) cout << "Chu vi Min = " << findMinPerimeter(a, n) << endl;
            else cout << "Danh sach rong!\n";
            break;

        case 5:
            if (n > 0) {
                int opt;
                cout << "Chon (1: Tang dan, 2: Giam dan): ";
                cin >> opt;
                sortListByPerimeter(a, n, opt == 1);
                cout << "Da sap xep xong!\n";
                printList(a, n);
            } else {
                cout << "Danh sach rong!\n";
            }
            break;

        case 6:
            if (n > 0) {
                int opt;
                cout << "Tim vi tri tam giac co chu vi (1: Max, 2: Min): ";
                cin >> opt;
                if (opt == 1) findPositionsByPerimeter(a, n, findMaxPerimeter(a, n));
                else findPositionsByPerimeter(a, n, findMinPerimeter(a, n));
            } else {
                cout << "Danh sach rong!\n";
            }
            break;

        case 7: {
            Triangle t;
            int pos;
            cout << "Nhap tam giac can them:\n";
            cout << "  Dinh A (x y): "; cin >> t.A.x >> t.A.y;
            cout << "  Dinh B (x y): "; cin >> t.B.x >> t.B.y;
            cout << "  Dinh C (x y): "; cin >> t.C.x >> t.C.y;
            cout << "Nhap vi tri chen (0 den " << n << "): ";
            cin >> pos;
            addTriangle(a, n, t, pos);
            break;
        }

        case 8: {
            char filename[255];
            cout << "Nhap ten file doc (vd: triangles.txt): ";
            cin >> filename;
            inputFromFile(a, n, filename);
            break;
        }

        case 9: {
            char filename[255];
            cout << "Nhap ten file ghi (vd: output_triangles.txt): ";
            cin >> filename;
            outputToFile(a, n, filename);
            break;
        }

        case 0:
            cout << "Thoat chuong trinh.\n";
            break;

        default:
            cout << "Lieu chon khong hop le, vui long nhap lai!\n";
        }
    } while (choice != 0);

    if (a) {
        delete[] a;
        a = nullptr;
    }

    return 0;
}