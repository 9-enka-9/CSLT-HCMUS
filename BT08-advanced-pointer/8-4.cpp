#include <iostream>
using namespace std;


int main() {
    // - int (*p)[4][6]
    // - int (*p)[6]
    // - int (*p)
    int m[4][6] = {
        { 0, 1, 2, 3, 4, 5},
        { 6, 7, 8, 9, 10, 11},
        {12, 13, 14, 15, 16, 17},
        {18, 19, 20, 21, 22, 23}
    };

    cout<<*(*(m+2)+4);
    return 0;
}