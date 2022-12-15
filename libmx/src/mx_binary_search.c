#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count){
    int bot = 0; 
    int top = size - 1;
    while (bot <= top){
        int mid = (bot + top) / 2;
        *count += 1;
        if(mx_strcmp(s, arr[mid]) < 0){
            top = mid - 1;
        }
        else if (mx_strcmp(s, arr[mid]) > 0){
            bot = mid + 1;
        }
        else {
            return mid;
        }
    }
    *count = 0;
    return -1;
}

