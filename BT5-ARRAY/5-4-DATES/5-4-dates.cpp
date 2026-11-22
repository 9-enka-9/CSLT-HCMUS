#include<bits/stdc++.h>
#include "dates.h"
using namespace std;
#define MAX 1000

int main(){
    int n;
    date dates[MAX];
    enterDates(n,dates);
    sortDate(n,dates);
    printDates(n,dates);
}