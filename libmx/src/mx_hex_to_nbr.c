#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex){
    int count = 0;
    while (*hex != '\0'){
        hex++;
        count++;
    }
    for (int i = 0; i < count; i++) hex--;
    if (count == 0) return 0;
    int pow = 16;
    unsigned long hexa = 1;
    unsigned long sum = 0;
    for (int i = count - 1; i >= 0; i--){
        if (mx_isalpha(hex[i]) == true){
            if (mx_islower(hex[i]) == true) sum += (hex[i] - 87) * hexa;
            if (mx_isupper(hex[i]) == true) sum += (hex[i] - 55) * hexa;
        }
        else if (mx_isdigit(hex[i]) == true){
            sum = (hex[i] - 48) * hexa;
        }
        hexa *= pow;
    }
    return sum;
}

bool mx_isalpha(int c){
    if ((c > 64 && c < 91) || (c > 96 && c < 123)){
        return 1;
    } else {
        return 0;
    }
}

bool mx_isdigit(int c){
    if (c >= 48 && c <= 57){
        return 1;
    } else {
        return 0;
    }
}

bool mx_islower(int c){
    if (c > 96 && c < 123){
        return 1;
    } else {
        return 0;
    }
}

bool mx_isupper(int c){
    if (c > 64 && c < 91){
        return 1;
    } else {
        return 0;
    }
}

