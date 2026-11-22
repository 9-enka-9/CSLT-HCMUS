#include <iostream>
#include <fstream>

using namespace std;

int isPrime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    ifstream fin("NUMBER.TXT");
    if (!fin) {
        cerr << "Error.";
    } else {
        ofstream fout("PRIME.TXT");
        if (!fout) {
            cerr << "Error.";
            fin.close();
        } else {
            int x;
            int first = 1;  
            while (fin >> x) { 
                if (isPrime(x)) {                
                    if (!first) fout << " ";
                    fout << x;    
                    first = 0;
                }
            }

            fin.close();
            fout.close();
        }
    }
    return 0;
}