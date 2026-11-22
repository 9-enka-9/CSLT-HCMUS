#include<bits/stdc++.h>
#include "students.h"
using namespace std;
#define MAX 1000

int main(){
    int n; 
    Student students[MAX];
    enterListStudents(n,students);
    listInDescending(n,students);
}