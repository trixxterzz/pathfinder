#include "../inc/libmx.h"

char *mx_strcat(char *s1, const char *s2){
    int firstLen = mx_strlen(s1);
    int i = 0;
    while (s2[i] != '\0') {
       s1[firstLen + i] = s2[i];
       i++;
    }
    s1[firstLen + i] = '\0';
    return s1;
}

