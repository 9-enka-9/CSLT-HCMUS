#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
#include <climits>

using namespace std;










// int* find_largest_sum_subarray(int *a, int n, int &largest_sum, int &subarray_length){
//     int maxsum=*a;
//     int *maxptr=a;
//     int maxlen=1;
//     for (int i=0;i<n;i++){
//         int sum=*(a+i);
//         if (sum>maxsum){
//             maxsum=sum;
//             maxlen = 1;
//             maxptr = a+i;
//         }
//         for (int j=i+1;j<n;j++){
//             sum+= *(a+j);
//             if (sum>maxsum){
//                 maxsum=sum;
//                 maxlen = j-i+1;
//                 maxptr = a+i;
//             }
//         }
//     }
//     largest_sum = maxsum;
//     subarray_length = maxlen;
//     return maxptr;
// }

// int* find_longest_ascending_subarray(int *a, int n, int &subarray_length){
//     int maxlen=1;
//     int *maxptr = a;
//     for (int i=1;i<n;i++){
//         int len=1;
//         for (int j=i;j<n;j++){
//             if (*(a+j)>*(a+j-1)){
//                 len++;
//             } else break;
//         }
//         if (len>maxlen){
//             maxlen=len;
//             maxptr = a+i-1;
//         }
//     }
//     subarray_length = maxlen;
//     return maxptr;
// }

// void swap_arrays(int *&a, int *&b, int &na, int &nb){
//     int *t = a;
//     a = b;
//     b = t;
    
//     int lent=na;
//     na = nb;
//     nb = lent;
// }

// int* concatenate_two_arrays(int *a, int *b, int na, int nb){
//     int *ray = new int[na+nb];
//     for (int i=0;i<na;i++){
//         ray[i]=a[i];
//     }
//     for (int i=0;i<nb;i++){
//         ray[i+na] = b[i];
//     }
//     return ray;
// }

// int* merge_two_arrays(int *a, int *b, int na, int nb, int &nc) {
//     int total = na + nb;
//     int *temp = concatenate_two_arrays(a, b, na, nb);
//     for (int i = 0; i < total - 1; i++) {
//         int min_index = i;
//         for (int j = i + 1; j < total; j++) {
//             if (temp[j] < temp[min_index]) {
//                 min_index = j;
//             }
//         }
//         int t = temp[min_index];
//         temp[min_index] = temp[i];
//         temp[i] = t;
//     }

//     nc = 1;
//     for (int i = 1; i < total; i++) {
//         if (temp[i] != temp[i - 1]) {
//             nc++;
//         }
//     }

//     int *res = new int[nc];
//     int idx = 0;
//     res[idx++] = temp[0];
//     for (int i = 1; i < total; i++) {
//         if (temp[i] != temp[i - 1]) {
//             res[idx++] = temp[i];
//         }
//     }
    
//     delete[] temp;

//     return res;
// }





// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int* sum(int *a, int *b){
//     int *p = new int((*a)+(*b));
//     return p;
// }

// void input_array(int *&a, int &n){
//     cin>>n;
//     a = new int[n];
//     for (int* p=a; p<a+n; p++){
//         cin>>*p;
//     } 
// }

// void print_array(int *a, int n){
//     for (int *p = a; p<a+n; p++){
//         cout<<*p;
//         if (p!=a+n-1) cout<<" ";
//     }
// }

// int* find_max(int *a, int n){
//     int *max = a;
//     for (int *p=a+1;p<a+n;p++){
//         if (*p>*max){
//             max = p;
//         }
//     }
//     return max;
// }

// int* copy_array(int *a, int n){
//     int *arr = new int [n];
//     for (int i=0;i<n;i++){
//         *(arr+i) = *(a+i); 
//     }
//     return arr;
// }

// int* count_evens(int *arr, int n, int *evens){
//     *evens=0;
//     for (int i=0;i<n;i++){
//         if (*(arr+i)%2==0) {
//             (*evens)++;
//         }
//     }
//     return evens;
// }

// int* generate_even_array(int *arr, int n, int *count){
//     count = count_evens(arr, n, count);
//     if (*count >0) {
//         int *res = new int[*count];
//         int cnt=0;
//         for (int i=0;i<n;i++){
//             if (arr[i]%2==0){
//                 res[cnt] = arr[i];
//                 cnt++;
//             }
//         }
//         return res;
//     }
//     return nullptr;
// }