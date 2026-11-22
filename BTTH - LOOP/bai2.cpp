#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int k;
    // TODO
    k=1;
    int sum=0;
    while (sum<=n){
        sum+=k;
        k++;
    }
    k-=2;
    // END TODO
    cout<<k;
    // return k;
}