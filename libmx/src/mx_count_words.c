#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter){
    if (str == NULL) return -1;
    int flag = 1;
    int count = 1;
    while (*str != '\0'){
        if (*(char*)str == delimiter){
            if (flag == 0){
                flag = 1;
                count++;
            }
        }
        else{
            flag = 0;
        }
        str++;
    }
    if (flag == 1){
        count--;
    }
    return count;
}

