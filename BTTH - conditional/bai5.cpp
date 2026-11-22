#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    int min,middle,max;
    max=a;
    if (max<b) max=b;
    if (max<c) max=c;
    
    if (max==a){
        min=(b>c)*c + (b<c)*b;
        middle = (b>c)*b + (b<c)*c;
    } else if (max==b) {
        min=(a>c)*c + (a<c)*a;
        middle=(a>c)*a + (a<c)*c;
    } else {
        min = (a>b)*b + (a<b)*a;
        middle = (a>b)*a + (b>a)*b;
    }
}