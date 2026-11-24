#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string increaseNumbers(const string& S) {
    string result = "";
    size_t i = 0;
    size_t len = S.length();

    while (i < len) {
        bool isNegativeNumber = (S[i] == '-' && i + 1 < len && isdigit(static_cast<unsigned char>(S[i + 1])));
        bool isPositiveNumber = isdigit(static_cast<unsigned char>(S[i]));

        if (isNegativeNumber || isPositiveNumber) {
            string numStr = "";
            
            if (S[i] == '-') {
                numStr += S[i];
                i++;
            }
            while (i < len && isdigit(static_cast<unsigned char>(S[i]))) {
                numStr += S[i];
                i++;
            }
            long long val = stoll(numStr);
            val += 1;
            result += to_string(val);

        } else {
            result += S[i];
            i++;
        }
    }

    return result;
}

int main() {
    string S;

    cout << "Enter a sentence = ";
    getline(cin, S);

    string result = increaseNumbers(S);
    cout << result << endl;

    return 0;
}