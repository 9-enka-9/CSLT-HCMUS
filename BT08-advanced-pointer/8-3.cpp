#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Enter a long paragraph (end with '.' and Enter):\n";

    string paragraph = "";
    string line;

    while (getline(cin, line)) {
        paragraph += line + "\n";

        if (!line.empty() && line.back() == '.') {
            break;
        }
    }

    cout << "--- PARAGRAPH ENTERED ---\n";
    cout << paragraph;

    return 0;
}