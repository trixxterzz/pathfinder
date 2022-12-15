#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size){
    int count = 0;
    for (int i = 1; i < size; i++){
        int flag = 0;
        for (int j = 0; j < size - i; j++){
            if (mx_strcmp(arr[j], arr[j+1]) > 0){
                char *buff = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = buff;
                count++;
                flag = 1;
            }
        }
        if (flag == 0) break;
    }

    return count;
}


