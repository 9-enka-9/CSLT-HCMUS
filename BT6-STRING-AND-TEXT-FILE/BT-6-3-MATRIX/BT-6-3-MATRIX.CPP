#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int a[100][100], b[100][100];
    int m, n;

    ifstream fin("MATRIX.TXT");
    if (!fin) {
        cerr << "Error." << endl;
    } else {
        fin >> m >> n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fin >> a[i][j];
            }
        }
        fin.close();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = a[j][n - 1 - i];
        }
    }

    ofstream fout("OUTPUT.TXT");
    if (!fout) {
        cerr << "Error." << endl;
    } else {
        fout << n << " " << m << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                fout << b[i][j] << " ";
            }
            fout << "\n";
        }
        fout.close();
    }

    return 0;
}