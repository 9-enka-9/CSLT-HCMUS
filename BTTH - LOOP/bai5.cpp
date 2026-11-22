#include<bits/stdc++.h>
using namespace std;

int main(){
    int result;
    int n; cin>>n;
    // TODO
    int ncopy=n;
    while (n!=0){
        result= result*10 + n%10;
        n/=10;
    }
    if (ncopy==result) result=1;
    else result=0;
    // END TODO
    cout<<result;
    // return result;
}