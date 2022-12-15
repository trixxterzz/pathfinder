#include "../inc/libmx.h"

void mx_del_strarr(char ***arr){
    if (arr == NULL) return;
    int i = 0;
    char **start = *arr;
    while ((*arr)[i] != NULL){
        mx_strdel(*arr);
        *arr += 1;
    }
    free(start);
    start = NULL;
}


