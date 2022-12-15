#include "../inc/libmx.h"


char *mx_nbr_to_hex(unsigned long nbr){
    unsigned long buff = nbr;
    int count = 0;
    while (buff > 0){
        buff = buff / 16;
        count++;
    }
    if (count == 0) return 0;
    char *s = mx_strnew(count);
    for (int i = 0; i < count - 1; i++){
        s++;
    }
    int rem = 0;
    while (nbr > 0){
        rem = nbr % 16;
        nbr = nbr / 16;
        if (rem > 9){
            *s = rem + 87;
        }
        else {
            *s = rem + 48;
        }
        if (nbr > 0) s--;
    }
    return s;
}

