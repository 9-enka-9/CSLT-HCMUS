#include <iostream>
#include "PhanSo.h"

using namespace std;

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
