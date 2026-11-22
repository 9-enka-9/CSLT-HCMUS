#include "array_1d_utils.h"
#include "format_utils.h"
#include <iostream>
#include <cmath>
using namespace std;

long long compute_array(int arr[], int n, char op){
    if (op=='+'){
        long long sum=0;
        for (int i=0;i<n;i++){
            sum+=arr[i];
        }
        return sum;
    }
    long long product=1;
    for (int i=0;i<n;i++){
        product*=arr[i];
    }
    return product;
}

float compute_mean(int arr[], int n){
    double average=compute_array(arr,n,'+');
    return round_to_decimal(average/n,2);
}

// 0 1 2 3 4 5
// 1 2 3 4 5 6

float compute_median(int arr[], int n){
    int arrcop[n];
    for (int i=0;i<n;i++){
        arrcop[i] = arr[i];
    }
    sort_ascending(arrcop,n);
    
    if (n%2!=0){
        return round_to_decimal(arrcop[n/2],2);
    }
    float m1 = arrcop[n/2-1], m2 = arrcop[n/2];
    return round_to_decimal((m1+m2)/2, 2);
}

int get_max_min(int arr[], int n, bool max){
    if (max){
        int arrmax=arr[0];
        for (int i=1;i<n;i++){
            if (arrmax<arr[i]){
                arrmax=arr[i];
            }
        }
        return arrmax;
    }
    int arrmin=arr[0];
    for (int i=1;i<n;i++){
        if (arrmin>arr[i]){
            arrmin=arr[i];
        }
    }
    return arrmin;
}


void sort_ascending(int arr[], int n){
    for (int i=0;i<n-1;i++){
        int min_index=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        int temp=arr[i];
        arr[i] = arr[min_index];
        arr[min_index]=temp;
    }
}

void sort_descending(int arr[], int n){
    for (int i=0;i<n-1;i++){
        int max_index=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]>arr[max_index]){
                max_index=j;            
            }
        }
        int temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }
}


// void input_array(int arr[], int n){
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
// }

// void print_array(int arr[], int n){
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }

// int search(int arr[], int n, int value){
//     for (int i=0;i<n;i++){
//         if (arr[i]==value) return i;
//     }
//     return -1;
// }

// bool add_at_index(int arr[], int& n, int value, int index){
//     if (index<0 or index>n){
//         return false;
//     }
//     for (int i=n;i>index;i--){
//         arr[i]=arr[i-1];
//     }
//     arr[index]=value;
//     n++;
//     return true;
// }

// bool remove_at_index(int arr[], int& n, int index){
//     if (index<0 or index>=n){
//         return false;
//     }
//     for (int i=index;i<n-1;i++){
//         arr[i]=arr[i+1];
//     }
//     n--;
//     return true;
// }