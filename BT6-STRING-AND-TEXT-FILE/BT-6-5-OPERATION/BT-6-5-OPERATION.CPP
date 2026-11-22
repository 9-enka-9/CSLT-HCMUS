#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("OPERATION.TXT");
    if (!fin) { 
        cerr << "Error.";
    } else {
        ofstream fout("RESULT.TXT");
        if (!fout) {
            cerr << "Error.";
            fin.close();
            return 1;
        } else {
            int a, b;
            char op;
            while (fin >> a >> op >> b) {
                if (op == '+')
                    fout << a + b << "\n";
                else if (op == '-')
                    fout << a - b << "\n";
                else if (op == '*')
                    fout << a * b << "\n";
                else if (op == '/') {
                    if (b == 0)
                        fout << "Divided by zero\n";
                    else
                        fout << a / b << "\n";
                }
            }

            fin.close();
            fout.close();
        }
    }
    return 0;
}