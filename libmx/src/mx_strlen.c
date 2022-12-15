#include "../inc/libmx.h"

int mx_strlen(const char *s){
    int i = 0;
    while (*s != '\0')
    {
        i++;
        s++;
    }
    return i;
}

