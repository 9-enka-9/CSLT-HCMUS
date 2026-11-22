#include<bits/stdc++.h>
using namespace std;

/*Ba cạnh tạo thành một tam giác hợp lệ khi:

a > 0, b > 0, c > 0;

Tổng độ dài của hai cạnh bất kỳ phải lớn hơn cạnh còn lại:

a + b > c

a + c > b

b + c > a

Nếu ba cạnh không thỏa các điều kiện trên, hàm trả về -1.

Nếu là tam giác hợp lệ, xác định loại tam giác và trả về:

1: Tam giác thường - không thuộc các loại đặc biệt bên dưới.

2: Tam giác cân - có ít nhất hai cạnh bằng nhau.

3: Tam giác đều - cả ba cạnh bằng nhau: a == b && b == c.

4: Tam giác vuông - bình phương cạnh lớn nhất bằng tổng bình phương của hai cạnh còn lại.*/

int main(){
    int a,b,c;
    if (a>0 and b>0 and c>0 and a+b>c and b+c>a and a+c>b){
        if (abs(a-b)<1e-6 and abs(b-c)<1e-6) return 3;
        else if (abs(a*a + b*b - c*c)<1e-6 
        or abs(b*b + c*c - a*a)<1e-6 
        or abs(a*a + c*c - b*b)<1e-6){
            return 4;
        } else if (abs(a-b)<1e-6 or abs(b-c)<1e-6 or abs(a-c)<1e-6) return 2;
        else return 1;
    }
    return -1;
}