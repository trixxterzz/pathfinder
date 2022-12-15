#include "../inc/libmx.h"

void mx_printint(int n){
    int flag = 0;
    if (n < 0){
        mx_printchar('-');
        while (n < -2147483647){
            n++;
            flag = 1;
        }
        n *= -1;
    }
    int num = n;
    int count = 0;
    if (num == 0){
        mx_printchar(num + 48);
        return;
    }
    while (num > 0){
        num = num / 10;
        count++;
    }
    int row = 1;
    for (int i = 1; i < count; i++){
        row = row * 10;
    }
    int asc = 48;
    for (int i = 0; i < count; i++){
        if (flag == 1 && i == count - 1) asc++;
        num = n;
        num = ((num / row) % 10) + asc;
        row = row / 10;
        write(1, &num, 1);
    }
}

