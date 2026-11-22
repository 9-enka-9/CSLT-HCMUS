#include <iostream>
#include <ctype.h>
using namespace std;

#define MAX_LEN 1000

int myStrLen(const char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char s[MAX_LEN];

    cout << "S = ";
    cin.getline(s, MAX_LEN);

    int freq[256] = {0};

    int maxFreq = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (!isspace((unsigned char)s[i])) {
            char c = s[i];
            freq[c]++;
            if (freq[c] > maxFreq) {
                maxFreq = freq[c];
            }
        }
    }
    for (int f = maxFreq; f >= 1; f--) {
        bool hasChar = false;
        for (int c = 0; c < 256; c++) {
            if (freq[c] == f) {
                hasChar = true;
                break;
            }
        }

        if (hasChar) {
            cout << f << ":";
            for (int c = 0; c < 256; c++) {
                if (freq[c] == f) {
                    cout << " " << c;
                }
            }
            cout << "\n";
        }
    }

    return 0;
}