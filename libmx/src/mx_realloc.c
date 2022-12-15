#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size){
    if (ptr == NULL) return malloc(size);
    if (size == 0) return malloc(0);
    size_t current = malloc_size(ptr);
    if (current >= size) return ptr;
    void *realloced = malloc(size);
    mx_memcpy(realloced, ptr, size);
    free(ptr);
    return realloced;
}

