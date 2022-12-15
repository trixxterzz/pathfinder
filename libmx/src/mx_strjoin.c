#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2){
    if (s1 == NULL && s2 == NULL) return NULL;
    if (s1 == NULL) return mx_strdup((char*)s2);
    char *dst = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    dst = mx_strcat(dst, s1);
    return mx_strcat(dst, s2);
}

