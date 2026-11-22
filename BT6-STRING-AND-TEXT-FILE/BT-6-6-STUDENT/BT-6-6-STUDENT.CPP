#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define MAX 100

using namespace std;

struct Student {
    string name;
    string id;
    float gpa;
};

void capitalize(string &s) {
    int newWord = 1;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            newWord = 1;
        } else if (newWord) {
            if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
            newWord = 0;
        } else {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        }
    }
}

int main() {
    ifstream fin("STUDENT.TXT");
    if (!fin) { 
        cerr << "Cannot open STUDENT.TXT\n"; 
        return 1; 
    }

    Student st[MAX];
    int n = 0;
    string line1, line2;

    while (n < MAX && getline(fin, line1) && getline(fin, line2)) {
        if (!line1.empty() && line1.back() == '\r') {
            line1.pop_back();
        }

        size_t barPos = line1.find('|');
        if (barPos == string::npos) continue;

        st[n].name = line1.substr(0, barPos);
        st[n].id = line1.substr(barPos + 1);

        capitalize(st[n].name);

        float sum = 0, p;
        int count = 0;
        stringstream ss(line2);
        while (ss >> p) {
            sum += p;
            count++;
        }
        st[n].gpa = (count > 0) ? sum / count : 0;
        n++;
    }
    fin.close();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (st[i].gpa < st[j].gpa) {
                Student tmp = st[i];
                st[i] = st[j];
                st[j] = tmp;
            }
        }
    }

    ofstream fout("GPA.TXT");
    if (!fout) { 
        cerr << "Cannot create GPA.TXT\n"; 
        return 1; 
    }
    
    for (int i = 0; i < n; i++) {
        fout << st[i].id << "|" << st[i].name << "|" << st[i].gpa << "\n";
    }
    fout.close();

    return 0;
}