#ifndef LAB_07
#define LAB_07

using namespace std;

int* find_largest_sum_subarray(int *a, int n, int &largest_sum, int &subarray_length);

int* find_longest_ascending_subarray(int *a, int n, int &subarray_length);

void swap_arrays(int *&a, int *&b, int &na, int &nb);

int* concatenate_two_arrays(int *a, int *b, int na, int nb);

int* concatenate_two_arrays(int *a, int *b, int na, int nb);

int* merge_two_arrays(int *a, int *b, int na, int nb, int &nc);



void swap(int *a, int *b);

int* sum(int *a, int *b);

void input_array(int *&a, int &n);

void print_array(int *a, int n);

int* find_max(int *a, int n);

int* copy_array(int *a, int n);

int* count_evens(int *arr, int n, int *evens);

int* generate_even_array(int *arr, int n, int *count);



#endif