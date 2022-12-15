#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub){
    if (str == NULL || sub == NULL) return -2;
    int len = mx_strlen(sub);
    for (int i = 0; str[i] != '\0'; i++){
        if (mx_strncmp(str, sub, len) == 0) return i;
        str++; 
    }
    return -1;
}

