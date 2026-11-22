#ifndef PHANSO_H
#define PHANSO_H

#include <string>

// Cấu trúc biểu diễn một phân số: tu / mau
struct PhanSo {
    long long tu;
    long long mau;
};

// Tìm ước chung lớn nhất (dùng để rút gọn phân số)
long long UCLN(long long a, long long b);

// Rút gọn phân số về dạng tối giản, đảm bảo mẫu luôn dương
PhanSo RutGon(PhanSo p);

// Nhập một phân số từ bàn phím, kiểm tra mẫu khác 0
PhanSo NhapPhanSo(const std::string &ten);

// In phân số ra màn hình dưới dạng tu/mau
void InPhanSo(PhanSo p);

// Cộng hai phân số: a/b + c/d = (a*d + b*c) / (b*d)
PhanSo Cong(PhanSo p1, PhanSo p2);

// Trừ hai phân số: a/b - c/d = (a*d - b*c) / (b*d)
PhanSo Tru(PhanSo p1, PhanSo p2);

// Nhân hai phân số: a/b * c/d = (a*c) / (b*d)
PhanSo Nhan(PhanSo p1, PhanSo p2);

// Chia hai phân số: a/b : c/d = (a*d) / (b*c)
// Trả về hopLe = false nếu phép chia không hợp lệ (chia cho phân số có tu so = 0)
PhanSo Chia(PhanSo p1, PhanSo p2, bool &hopLe);

#endif // PHANSO_H
