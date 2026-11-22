#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int length = 0;
    // TODO
    while (n!=1){
        length++;
        if (n%2==0) n/=2;
        else n = 3*n+1;
    }
    // END TODO
    cout<<length;
    // return length;
}