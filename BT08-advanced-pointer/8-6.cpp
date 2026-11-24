#include <iostream>
#include <fstream>
using namespace std;

void printList(const int* a, int n) {
    if (!a || n <= 0) {
        cout << "Danh sach dang rong!\n";
        return;
    }
    cout << "Danh sach (" << n << " phan tu): ";
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
    cout << endl;
}

void inputList(int*& a, int& n) {
    if (a) {
        delete[] a;
        a = nullptr;
    }
    cout << "Nhap so luong phan tu n = ";
    cin >> n;
    if (n <= 0) {
        n = 0;
        return;
    }
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> *(a + i);
    }
}

int findMax(const int* a, int n) {
    int maxVal = *a;
    for (int i = 1; i < n; i++) {
        if (*(a + i) > maxVal) {
            maxVal = *(a + i);
        }
    }
    return maxVal;
}

int findMin(const int* a, int n) {
    int minVal = *a;
    for (int i = 1; i < n; i++) {
        if (*(a + i) < minVal) {
            minVal = *(a + i);
        }
    }
    return minVal;
}

void sortList(int* a, int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && *(a + i) > *(a + j)) || (!ascending && *(a + i) < *(a + j))) {
                int temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}
\
void findPositions(const int* a, int n, int val) {
    bool found = false;
    cout << "Cac vi tri (index) xuat hien gia tri " << val << ": ";
    for (int i = 0; i < n; i++) {
        if (*(a + i) == val) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay!";
    }
    cout << endl;
}
\
void addElement(int*& a, int& n, int val, int pos) {
    if (pos < 0 || pos > n) {
        cout << "Vi tri chen khong hop le!\n";
        return;
    }
    int* temp = new int[n + 1];

    for (int i = 0; i < pos; i++) {
        *(temp + i) = *(a + i);
    }
    *(temp + pos) = val;
    for (int i = pos; i < n; i++) {
        *(temp + i + 1) = *(a + i);
    }

    delete[] a; 
    a = temp; 
    n++;
    cout << "Da them " << val << " vao vi tri " << pos << " thanh cong!\n";
}

void inputFromFile(int*& a, int& n, const char* filename) {
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
        a = new int[n];
        for (int i = 0; i < n; i++) {
            fin >> *(a + i);
        }
        cout << "Da doc thanh cong " << n << " phan tu tu file " << filename << "!\n";
    } else {
        n = 0;
        cout << "File ranh hoac so luong phan tu khong hop le!\n";
    }
    fin.close();
}

void outputToFile(const int* a, int n, const char* filename) {
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
        fout << *(a + i) << " ";
    }
    fout << "\n";
    fout.close();
    cout << "Da ghi danh sach ra file " << filename << " thanh cong!\n";
}

int main() {
    int* a = nullptr;
    int n = 0;
    int choice;

    do {
        cout << "\n================= MENU MANAGING LIST =================";
        cout << "\n1. Print the list";
        cout << "\n2. Input the list";
        cout << "\n3. Find the maximum element";
        cout << "\n4. Find the minimum element";
        cout << "\n5. Sort the list (1: Ascending / 2: Descending)";
        cout << "\n6. Find positions of Max / Min element";
        cout << "\n7. Add an element (at end or any position)";
        cout << "\n8. Input the list from a text file";
        cout << "\n9. Output the list to a text file";
        cout << "\n0. Exit";
        cout << "\n------------------------------------------------------";
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
            if (n > 0) cout << "Gia tri Max = " << findMax(a, n) << endl;
            else cout << "Danh sach rong!\n";
            break;

        case 4:
            if (n > 0) cout << "Gia tri Min = " << findMin(a, n) << endl;
            else cout << "Danh sach rong!\n";
            break;

        case 5:
            if (n > 0) {
                int opt;
                cout << "Chon (1: Tang dan, 2: Giam dan): ";
                cin >> opt;
                sortList(a, n, opt == 1);
                cout << "Da sap xep xong!\n";
                printList(a, n);
            } else {
                cout << "Danh sach rong!\n";
            }
            break;

        case 6:
            if (n > 0) {
                int opt;
                cout << "Tim vi tri cua (1: Max, 2: Min): ";
                cin >> opt;
                if (opt == 1) findPositions(a, n, findMax(a, n));
                else findPositions(a, n, findMin(a, n));
            } else {
                cout << "Danh sach rong!\n";
            }
            break;

        case 7: {
            int val, pos;
            cout << "Nhap gia tri can thêm: ";
            cin >> val;
            cout << "Nhap vi tri chen (0 den " << n << "): ";
            cin >> pos;
            addElement(a, n, val, pos);
            break;
        }

        case 8: {
            char filename[255];
            cout << "Nhap ten file doc (vd: input.txt): ";
            cin >> filename;
            inputFromFile(a, n, filename);
            break;
        }

        case 9: {
            char filename[255];
            cout << "Nhap ten file ghi (vd: output.txt): ";
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