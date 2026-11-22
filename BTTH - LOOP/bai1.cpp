#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=52;
    string result="";
    // TODO
    for (int i=1;i<=n/2+1;i++){
        if (n%i==0){
            result+=to_string(i);
            result+=" ";
        }
    }
    result += to_string(n);
    // END TODO
    cout<<result;
    // return result;
}