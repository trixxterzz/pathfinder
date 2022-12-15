#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n){
    for (size_t i = 0; i < n; i++){
        ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
        if (((unsigned char *)src)[i] == c){
            return (void *)&(((unsigned char *)dst)[i + 1]);
        }
    }
    return NULL;
}

