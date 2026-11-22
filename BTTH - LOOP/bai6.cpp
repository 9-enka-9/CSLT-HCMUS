#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b; cin>>a>>b;
    int lcm;
    // TODO
    int acopy=a,bcopy=b;
    while (a!=b){
        if (a>b){
            a-=b;
        } else {
            b-=a;
        }
    }
    lcm=acopy*bcopy/a;
    // END TODO
    cout<<lcm;
    // return lcm;
}