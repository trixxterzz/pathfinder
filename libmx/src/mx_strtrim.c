#include "../inc/libmx.h"

bool mx_isspace(int c){
    if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v') return true;
    return false;
}

char *mx_strtrim(const char *str){
    if (str == NULL) return NULL;
    char *buff = (char *)str;
    int spaces = 0;
    int spaces1 = 0;
    while (mx_isspace(*buff) == true){
        buff++;
        spaces++;
    }
    for (int i = mx_strlen(buff) - 1; i >= 0; i--){
        if (mx_isspace(buff[i]) == true) spaces1++;
        if (mx_isspace(buff[i]) == false) break;
    }
    char *new = mx_strnew(mx_strlen(str) - spaces);
    new = mx_strncpy(new, buff, mx_strlen(buff) - spaces1);
    return new;
}


