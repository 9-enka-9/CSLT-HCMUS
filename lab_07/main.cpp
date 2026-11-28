#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
#include <climits>
#include "lab_07.h"
using namespace std;

int main(){
    int arr1[100];
    int arr2[100];
    int n1, n2;
    cin>>n1;
    for (int i=0; i<n1; i++){
        cin>>arr1[i];
    }
    cin>>n2;
    for (int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    // int largestsum, largestlen;
    // cout<<*find_largest_sum_subarray(arr,n,largestsum, largestlen)<< " "<<largestsum<<" "<<largestlen<<endl;
    
    int nc;
    int *a12 = merge_two_arrays(arr1, arr2, n1,n2, nc);
    for (int i=0;i<nc;i++){
        cout<<a12[i]<<" ";
    }
    delete[] a12;
    a12=nullptr;
    
    // int sum, len;
    // cout<<*find_longest_ascending_subarray(arr1, n1,len)<<" "<<len;
    return 0;
}