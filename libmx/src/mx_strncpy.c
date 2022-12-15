#include "../inc/libmx.h"

char *mx_strncpy(char *dst, char *src, int len){
    if (src == NULL) return NULL;
    char *ptr = dst;
    for (int i = 0; i < len; i++){
        *dst = *(char*)src;
        dst++;
        src++;
    }
    *dst = '\0';
    return ptr;
}

