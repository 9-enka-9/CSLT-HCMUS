#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long n; cin>>n;
    int length = 0;
    // TODO
    int start=0, i=0;
    bool dangle=false;
    while (n!=0){
        int digit=n%10;
        n/=10;
        if (digit%2!=0) {
            if (!dangle) {
                start=i;
                dangle=true;
            }
        } else if (dangle){
            dangle=false;
            if (length<i-start) length=i-start;
        }
        i++;
    }
    if (dangle){
        if (length<i-start) length=i-start;
    }
    // END TODO
    cout<<length;
    // return length;
}