#include "../inc/libmx.h"

char *mx_strcpy(char *dst, char *src){
    char *ptr = dst;
    while (*src != '\0'){
        *dst = *src;
        src++;
        dst++;
    }
    while (*dst != '\0'){
        *dst = '\0';
        dst++;
    }
    return ptr;
}

