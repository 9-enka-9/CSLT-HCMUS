#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* sum(int *a, int *b){
    int *p = new int((*a)+(*b));
    return p;
}

void input_array(int *&a, int &n){
    cin>>n;
    a = new int[n];
    for (int* p=a; p<a+n; p++){
        cin>>*p;
    } 
}

void print_array(int *a, int n){
    for (int *p = a; p<a+n; p++){
        cout<<*p;
        if (p!=a+n-1) cout<<" ";
    }
}

int* find_max(int *a, int n){
    int *max = a;
    for (int *p=a+1;p<a+n;p++){
        if (*p>*max){
            max = p;
        }
    }
    return max;
}

int* copy_array(int *a, int n){
    int *arr = new int [n];
    for (int i=0;i<n;i++){
        *(arr+i) = *(a+i); 
    }
    return arr;
}

int* count_evens(int *arr, int n, int *evens){
    *evens=0;
    for (int i=0;i<n;i++){
        if (*(arr+i)%2==0) {
            (*evens)++;
        }
    }
    return evens;
}

int* generate_even_array(int *arr, int n, int *count){
    count = count_evens(arr, n, count);
    if (*count >0) {
        int *res = new int[*count];
        int cnt=0;
        for (int i=0;i<n;i++){
            if (arr[i]%2==0){
                res[cnt] = arr[i];
                cnt++;
            }
        }
        return res;
    }
    return nullptr;
}