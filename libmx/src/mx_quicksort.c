#include "../inc/libmx.h"


void mx_swap(char *s1, char *s2){
    char *buff = s1;
    s1 = s2;
    s2 = buff;
}

int mx_part(char **arr, int *swaps, int left, int right){
    int elem = mx_strlen(arr[right]);
    int i = left;
    for (int j = left; j < right; j++){
        if (mx_strlen(arr[j]) <= elem){
            char *buff = arr[j];
            arr[j] = arr[i];
            arr[i] = buff;
            if (j != i) *swaps += 1;
            i++;
        }
    }
    if (i != right){
        char *buff = arr[i];
        arr[i] = arr[right];
        arr[right] = buff;
        *swaps += 1;
    }
    else{
        i--;
    }
    return i;
}

void mx_quicksort_rec(char **arr, int *swaps, int left, int right){
    if (left < right){
        int based = mx_part(arr, swaps, left, right);
        if (left < based && based != right) mx_quicksort_rec(arr, swaps, left, based);
        mx_quicksort_rec(arr, swaps, based + 1, right);
    }
    return;
}

int mx_quicksort(char **arr, int left, int right){
    if (arr == NULL) return -1;
    int swaps = 0;
    mx_quicksort_rec(arr, &swaps, left, right);
    return swaps;
}

