#include "libmx.h"

char *mx_remove_dups(char *arr[], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        j = i + 1;
        while (j < n) {
            if (mx_strcmp(arr[i], arr[j]) == 0) {
                mx_memmove(arr + j, arr + n - 1, sizeof(arr[n - 1]));
                n--;
            }
            else 
                j++;
        }
    }
    return *arr;
}
