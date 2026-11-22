#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    ifstream fin("INPUT.TXT");
    if (!fin) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int word_count = 0;
    int number_count = 0;
    char ch;

    bool in_word = false;
    bool in_number = false;

    while (fin.get(ch)) {
        if (isalpha(ch)) {
            if (!in_word) {
                word_count++;
                in_word = true;
            }
            in_number = false; 
        } 
        else if (isdigit(ch)) {
            if (!in_number) {
                number_count++;
                in_number = true;
            }
            in_word = false; 
        } 
        else {
            in_word = false;
            in_number = false;
        }
    }

    fin.close();
    
    cout << "Word count: " << word_count << "." << endl;
    cout << "Number count: " << number_count << "." << endl;

    return 0;
}