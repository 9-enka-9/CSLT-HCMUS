#include <iostream>
#include <cstdlib>  // abs
using namespace std;

// Cấu trúc biểu diễn một phân số: tu / mau
struct PhanSo {
    long long tu;
    long long mau;
};

// Tìm ước chung lớn nhất (dùng để rút gọn phân số)
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

// Rút gọn phân số về dạng tối giản, đảm bảo mẫu luôn dương
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

// Nhập một phân số từ bàn phím, kiểm tra mẫu khác 0
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

// In phân số ra màn hình dưới dạng tu/mau
void InPhanSo(PhanSo p) {
    cout << p.tu << "/" << p.mau;
}

// Cộng hai phân số: a/b + c/d = (a*d + b*c) / (b*d)
PhanSo Cong(PhanSo p1, PhanSo p2) {
    PhanSo kq;
    kq.tu = p1.tu * p2.mau + p2.tu * p1.mau;
    kq.mau = p1.mau * p2.mau;
    return RutGon(kq);
}

// Trừ hai phân số: a/b - c/d = (a*d - b*c) / (b*d)
PhanSo Tru(PhanSo p1, PhanSo p2) {
    PhanSo kq;
    kq.tu = p1.tu * p2.mau - p2.tu * p1.mau;
    kq.mau = p1.mau * p2.mau;
    return RutGon(kq);
}

// Nhân hai phân số: a/b * c/d = (a*c) / (b*d)
PhanSo Nhan(PhanSo p1, PhanSo p2) {
    PhanSo kq;
    kq.tu = p1.tu * p2.tu;
    kq.mau = p1.mau * p2.mau;
    return RutGon(kq);
}

// Chia hai phân số: a/b : c/d = (a*d) / (b*c)
// Trả về kq.mau = 0 nếu phép chia không hợp lệ (chia cho phân số 0/x)
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

// Hiện menu lựa chọn và trả về số nguyên người dùng chọn
int HienMenu() {
    int chon;
    cout << "\n================ MENU ================\n";
    cout << "1. Cong hai phan so\n";
    cout << "2. Tru hai phan so\n";
    cout << "3. Nhan hai phan so\n";
    cout << "4. Chia hai phan so\n";
    cout << "0. Thoat\n";
    cout << "=======================================\n";
    cout << "Chon mot chuc nang: ";
    cin >> chon;
    return chon;
}

int main() {
    cout << "=== CHUONG TRINH CONG, TRU, NHAN, CHIA HAI PHAN SO ===\n";

    int chon;
    do {
        chon = HienMenu();

        // Thoat khong can nhap phan so
        if (chon == 0) {
            cout << "Tam biet!\n";
            break;
        }

        if (chon < 0 || chon > 4) {
            cout << "Lua chon khong hop le. Vui long chon lai!\n";
            continue;
        }

        PhanSo p1 = RutGon(NhapPhanSo("phan so thu nhat"));
        PhanSo p2 = RutGon(NhapPhanSo("phan so thu hai"));

        switch (chon) {
            case 1: { // Cong
                PhanSo tong = Cong(p1, p2);
                InPhanSo(p1); cout << " + "; InPhanSo(p2); cout << " = "; InPhanSo(tong); cout << "\n";
                break;
            }
            case 2: { // Tru
                PhanSo hieu = Tru(p1, p2);
                InPhanSo(p1); cout << " - "; InPhanSo(p2); cout << " = "; InPhanSo(hieu); cout << "\n";
                break;
            }
            case 3: { // Nhan
                PhanSo tich = Nhan(p1, p2);
                InPhanSo(p1); cout << " * "; InPhanSo(p2); cout << " = "; InPhanSo(tich); cout << "\n";
                break;
            }
            case 4: { // Chia
                bool hopLe;
                PhanSo thuong = Chia(p1, p2, hopLe);
                InPhanSo(p1); cout << " / "; InPhanSo(p2); cout << " = ";
                if (hopLe) {
                    InPhanSo(thuong);
                    cout << "\n";
                } else {
                    cout << "Khong xac dinh (chia cho phan so co tu so = 0)\n";
                }
                break;
            }
        }
    } while (chon != 0);

    return 0;
}
