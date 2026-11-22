#include "PhanSo.h"
#include <iostream>
#include <cstdlib>  // abs

using namespace std;

long long UCLN(long long a, long long b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        long long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

PhanSo RutGon(PhanSo p) {
    if (p.tu == 0) {
        p.mau = 1;
        return p;
    }
    long long g = UCLN(p.tu, p.mau);
    if (g != 0) {
        p.tu /= g;
        p.mau /= g;
    }
    // Chuẩn hóa dấu: mẫu luôn dương
    if (p.mau < 0) {
        p.tu = -p.tu;
        p.mau = -p.mau;
    }
    return p;
}

PhanSo NhapPhanSo(const string &ten) {
    PhanSo p;
    while (true) {
        cout << "Nhap tu so va mau so cua " << ten << " (vd: 3 4): ";
        cin >> p.tu >> p.mau;
        if (p.mau == 0) {
            cout << "Mau so khong duoc bang 0. Vui long nhap lai!\n";
            continue;
        }
        break;
    }
    return p;
}

void InPhanSo(PhanSo p) {
    cout << p.tu << "/" << p.mau;
}

PhanSo Cong(PhanSo p1, PhanSo p2) {
    PhanSo kq;
    kq.tu = p1.tu * p2.mau + p2.tu * p1.mau;
    kq.mau = p1.mau * p2.mau;
    return RutGon(kq);
}

PhanSo Tru(PhanSo p1, PhanSo p2) {
    PhanSo kq;
    kq.tu = p1.tu * p2.mau - p2.tu * p1.mau;
    kq.mau = p1.mau * p2.mau;
    return RutGon(kq);
}

PhanSo Nhan(PhanSo p1, PhanSo p2) {
    PhanSo kq;
    kq.tu = p1.tu * p2.tu;
    kq.mau = p1.mau * p2.mau;
    return RutGon(kq);
}

PhanSo Chia(PhanSo p1, PhanSo p2, bool &hopLe) {
    PhanSo kq;
    hopLe = true;
    if (p2.tu == 0) {
        hopLe = false;
        kq.tu = 0;
        kq.mau = 1;
        return kq;
    }
    kq.tu = p1.tu * p2.mau;
    kq.mau = p1.mau * p2.tu;
    return RutGon(kq);
}
