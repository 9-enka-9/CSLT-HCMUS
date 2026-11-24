#include <iostream>
#include <cstring> 

using namespace std;

char* replaceAll(const char* S, const char* F, const char* R) {
    if (!S || !F || !R) return nullptr;

    int lenS = strlen(S);
    int lenF = strlen(F);
    int lenR = strlen(R);

    if (lenF == 0) {
        char* copyS = new char[lenS + 1];
        strcpy(copyS, S);
        return copyS;
    }

    int count = 0;
    const char* p = S;
    while ((p = strstr(p, F)) != nullptr) {
        count++;
        p += lenF;
    }

    int newLen = lenS + count * (lenR - lenF) + 1;
    char* result = new char[newLen];
    result[0] = '\0';

    const char* current = S;
    while ((p = strstr(current, F)) != nullptr) {
        strncat(result, current, p - current);
        strcat(result, R);
        current = p + lenF;
    }
    
    strcat(result, current);
    return result;
}

int main() {
    char S[1000], F[100], R[100];

   cout << "Enter a sentence = ";
   cin.getline(S, 1000);

   cout << "Enter find word = ";
   cin.getline(F, 100);

   cout << "Enter replacing word = ";
   cin.getline(R, 100);


    char* result = replaceAll(S, F, R);

    if (result) {
        cout << result <<endl;
        delete[] result; 
        result = nullptr;
    }

    return 0;
}
