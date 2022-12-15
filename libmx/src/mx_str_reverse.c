#include "../inc/libmx.h"
void mx_str_reverse(char *s){
    int length = 0;
    while(*s != '\0'){
        length++;
        s++;
    }
    for (int i = 0; i < length; i++){
        s--;
    }
    int limit = length / 2;
    for (int i = 0; i < limit; i++){
        char buff = s[i];
        s[i] = s[length - 1 - i];
        s[length - 1 - i] = buff;
    }
}

