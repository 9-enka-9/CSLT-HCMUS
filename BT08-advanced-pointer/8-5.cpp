// a) 
// 1
// stack: 8 bytes * 10 = 80 bytes (64-bit)
// heap: 0 bytes
// 2
// stack: 80 bytes
// heap: (1+2+3+4+5)*8 bytes = 120 bytes (64-bit)
// 3
// stack: 80 bytes
// heap: 0 bytes

// b) ham initialize truyen dia chi của con tro p+3
// cap phat bo nho dong cho cac vi tri con tro p+i

#include <iostream>
using namespace std;

void initialize(double **p) {
    for (int i = 0; i < 5; i++) {
        *(p + i) = new double[i + 1];
    }
}

void release(double **p) {
    for (int i = 3; i <= 7; i++) {
        delete[] p[i];
        p[i] = nullptr;
    }
}

int main() {
    double *p[2] = {nullptr};

    initialize(p + 3);

    for (int i = 3; i <= 7; i++) {
        cout << "p[" << i << "] points to array of size " << (i - 2) << endl;
    }

    release(p);

    return 0;
}



