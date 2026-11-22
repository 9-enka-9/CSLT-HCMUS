#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int result = 0;
    // TODO
    while (n!=0){
        result= result*10 + n%10;
        n/=10;
    }
    // END TODO
    cout<<result;
    // return result;
}