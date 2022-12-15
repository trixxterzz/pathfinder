#include "../inc/libmx.h"

char *mx_itoa(int number){
    int num_len = 0;
    if (number == 0) num_len = 1;
    int buff = number;
    while (buff != 0){
        buff /= 10;
        num_len++;
    }
    char *res = mx_strnew(num_len);
    char *start = res;
    if (number < 0){
        *res = '-';
        res++;
        number *= -1;
    }
    double powed = mx_pow(10, num_len - 1);
    for (int i = 0; i < num_len; i++){
        int buff = (number / powed);
        buff %= 10;
        powed /= 10;
        *res = buff + 48;
        res++;
    }
    *res = '\0';
    return start;
}

