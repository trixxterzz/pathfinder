#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len){
    if (big_len < little_len || big_len < 0 || little_len < 0) return NULL;
    void *str_temp = mx_memchr(big, ((unsigned char *)little)[0], big_len);
    unsigned char *str_buff = (unsigned char *)str_temp;
    unsigned char *sub_buff = (unsigned char *)little;
    while (str_buff != NULL){
        if (mx_memcmp(str_buff, sub_buff, little_len - 1) == 0){
            return (void *)str_buff;
        }
        else {
            str_temp = mx_memchr((void *)(((unsigned char *)str_temp) + 1), ((unsigned char *)little)[0], big_len);
            str_buff = (unsigned char *)str_temp;
        }
    }
    return NULL;
}

