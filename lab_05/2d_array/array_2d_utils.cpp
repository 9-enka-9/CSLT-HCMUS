#include "array_2d_utils.h"
#include <iostream>
#include <cmath>

#include "format_utils.h"

using namespace std;

void sort_ascending_2d(int arr[][MAX_COLS], int rows, int cols, bool row_based){
    if (row_based==true){
        for (int i=0;i<rows;i++){
            for (int j=0;j<cols-1;j++){
                for (int k=j+1;k<cols;k++){
                    int max_index = j;
                    if (arr[i][max_index]>arr[i][k]){
                        max_index = k;
                    }
                    int temp = arr[i][j];
                    arr[i][j] = arr[i][max_index];
                    arr[i][max_index] = temp;
                }
            }
        }
    } else {
        for (int i=0;i<cols;i++){
            for (int j=0;j<rows-1;j++){
                for (int k=j+1;k<rows;k++){
                    int max_index = j;
                    if (arr[max_index][i]>arr[k][i]){
                        max_index = k;
                    }
                    int temp = arr[j][i];
                    arr[j][i] = arr[max_index][i];
                    arr[max_index][i] = temp;
                }
            }
        }
    }
}

void sort_descending_2d(int arr[][MAX_COLS], int rows, int cols, bool row_based){
    if (row_based){
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols-1; j++){
                int min_index=j;
                for (int k=j+1; k<cols; k++){
                    if (arr[i][min_index]<arr[i][k]){
                        min_index=k;
                    }
                }
                int temp = arr[i][j];
                arr[i][j] = arr[i][min_index];
                arr[i][min_index] = temp;
            }
        }
    } else {
        for (int i=0; i<cols; i++){
            for (int j=0; j<rows-1; j++){
                int min_index=j;
                for (int k=j+1; k<rows; k++){
                    if (arr[min_index][i]<arr[k][i]){
                        min_index=k;
                    }
                }
                int temp=arr[j][i];
                arr[j][i]=arr[min_index][i];
                arr[min_index][i]=temp;
            }
        }
    }
}

void swap_2d(int arr[][MAX_COLS], int rows, int cols, int first_index, 
            int second_index, bool row_based){
    if (row_based){
        for (int i=0;i<cols;i++){
            int temp = arr[first_index][i];
            arr[first_index][i] = arr[second_index][i];
            arr[second_index][i] = temp;
        }
    } else {
        for (int i=0;i<rows;i++){
            int temp = arr[i][first_index];
            arr[i][first_index] = arr[i][second_index];
            arr[i][second_index] = temp;
        }
    }
}
void transpose_2d(int arr[][MAX_COLS], int rows, int cols){
    for (int i=0;i<rows;i++){
        for (int j=i+1; j<cols;j++ ){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
}

void rotate_2d(int arr[][MAX_COLS], int rows, int cols, int n){
    for (int i=0;i<n;i++){
        int arrcop[MAX_ROWS][MAX_COLS];
        for (int j=0;j<rows;j++){
            for (int k=0;k<rows;k++){
                arrcop[k][rows-j-1]=arr[j][k];
            }
        }
        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                arr[i][j]=arrcop[i][j];
            }
        }
    }
}

void reverse_2d(int arr[][MAX_COLS], int rows, int cols, bool row_based){
    if (row_based){
        for (int i=0;i<rows/2;i++){
            for (int j=0;j<cols;j++){
                int temp = arr[i][j];
                arr[i][j]=arr[rows-i-1][j];
                arr[rows-i-1][j]=temp;
            }
        }
    }else {
        for (int i=0;i<rows;i++){
            for (int j=0;j<cols/2;j++){
                int temp = arr[i][j];
                arr[i][j]=arr[i][cols-j-1];
                arr[i][cols-j-1] = temp;
            }
        }
    }
}





// void input_2d(int arr[][MAX_COLS], int rows, int cols){
//     for (int i=0;i<rows;i++){
//         for (int j=0;j<cols;j++){
//             cin>>arr[i][j];
//         }
//     }
// }

// void print_2d(int arr[][MAX_COLS], int rows, int cols){
//     for (int i=0;i<rows;i++){
//         for (int j=0;j<cols;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }


// bool check_exist(int arr[][MAX_COLS], int rows, int cols, int value){
//     for (int i=0;i<rows;i++){
//         for(int j=0;j<cols;j++){
//             if (arr[i][j] == value){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// long long compute_2d(int arr[][MAX_COLS], int rows, int cols, char op){
//     if (op=='+'){
//         long long sum=0;
//         for (int i=0;i<rows;i++){
//             for (int j=0;j<cols;j++){
//                 sum+=arr[i][j];
//             }
//         }
//         return sum;
//     }
//     long long product=1;
//     for (int i=0;i<rows;i++){
//         for (int j=0;j<cols;j++){
//             product*=arr[i][j];
//         }
//     }
//     return product;
// }

// float compute_mean_2d(int arr[][MAX_COLS], int rows, int cols){
//     double average=(double)compute_2d(arr,rows,cols,'+')/(double)(rows*cols);
//     return round_to_decimal(average,2);
//     //round_to_decimal!!!!
// }

// int get_max_min_2d(int arr[][MAX_COLS], int rows, int cols, bool max){
//     if (max){
//         int maxArr=arr[0][0];
//         for (int i=0;i<rows;i++){
//             for (int j=0;j<cols;j++){
//                 if (maxArr<arr[i][j]) maxArr=arr[i][j];
//             }
//         }
//         return maxArr;
//     } else {
//         int minArr=arr[0][0];
//         for (int i=0;i<rows;i++){
//             for (int j=0;j<cols;j++){
//                 if (minArr>arr[i][j]) minArr=arr[i][j];
//             }
//         }
//         return minArr;
//     }
// }