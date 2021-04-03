#include "libmx.h"

void mx_swap_int(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int mx_partition(int *arr, int left, int right, int *swap) {
    int pivot = arr[right];
    int i = left;
    int j = right - 1;

    if (i == j) {
        if (arr[i] > arr[i+1]) {
            mx_swap_int(&arr[i], &arr[i+1]);
            (*swap)++;
        }
        return -1;
    }    
    while (i <= j) {      
        if (arr[i] > pivot) {
            if (arr[j] < pivot) {
                mx_swap_int(&arr[i], &arr[j]);
                i++;
                j--;
                (*swap)++;
            }
             else j--;   
        }    
        else i++;
    } 
    if (arr[i] > arr[right]) {
        mx_swap_int(&arr[i], &arr[right]);
        (*swap)++;
    }   
    return i;
}

int mx_quicksort(int *arr, int left, int right) {
    int swap = 0;
    int pivot;

    if (!arr || left < 0 || right < 0)
        return -1;
    if (left < right) {
        pivot = mx_partition(arr, left, right, &swap);
        if (pivot == -1) {
            return swap;
        }
        swap += mx_quicksort(arr, left, pivot - 1);
        swap += mx_quicksort(arr, pivot + 1, right);
    }
    return swap;
}
