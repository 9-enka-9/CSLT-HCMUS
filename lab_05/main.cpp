#include <iostream>

// #include "1d_array/array_1d_utils.h"
#include "2d_array/array_2d_utils.h"
#include "utils/format_utils.h"

using namespace std;
#define MAX 100

int main(){
    // int arr[MAX][MAX] = {{3,7,4},{6,4,5},{8,3,1},{2,4,6}};
    int arr[MAX][MAX] = {{1,2,3},{4,5,6},{7,8,9}};
    int rows=3,cols=3;
    
    reverse_2d(arr,rows,cols,false);
    print_2d(arr,rows,cols);
    cout<<endl;
    
    
    
    
    // int arr[MAX][MAX];
    // int rows=2, cols = 3;
    // input_2d(arr,rows, cols);
    // print_2d(arr,rows,cols);
    // cout<<endl;
    
    // int value=3;
    // cout<<check_exist(arr, rows, cols, value)<<endl;
    
    // char op = '+';
    // cout<<compute_2d(arr,rows, cols, op)<<endl;
    
    // cout<<compute_mean_2d(arr, rows, cols)<<endl;
    
    // cout<<get_max_min_2d(arr,rows, cols,true);
        
    
    // int arr[]={23,10,30,0,10,0};
    // int n=6;
    // cout<<compute_array(arr,n)<<endl;
    // cout<<compute_mean(arr,n)<<endl;
    // cout<<compute_median(arr,n)<<endl;
    // cout<<get_max_min(arr,n,false)<<endl;
    // sort_ascending(arr,n);
    // for (int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // sort_descending(arr,n);
    // for (int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    
    
    // // TODO
    // int n;
    // int arr[MAX];
    // cin>>n;
    // input_array(arr,n);
    // print_array(arr,n);
    
    // // void input_array(int arr[], int n);
    // // void print_array(int arr[], int n);
    // // int search(int arr[], int n, int value);
    // // bool add_at_index(int arr[], int& n, int value, int index);
    // // bool remove_at_index(int arr[], int& n, int index);
    // // int val;
    
    // // cin>>val;
    // // cout<<search(arr, n, val);
    
    // int index;
    // // cin>>val>>index;
    // // add_at_index(arr,n,val, index);
    // // print_array(arr,n);
    
    // cin>>index;
    // cout<<remove_at_index(arr, n, index);
    // print_array(arr,n);
    // // END TODO
    // return 0;
}