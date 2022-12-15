#include "../inc/libmx.h"

char *mx_file_to_str(const char *file){
    int f = open(file, O_RDONLY);
    if (errno != 0) return NULL;
    char buff[1];
    int rd = read(f, &buff[0], 1);
    char *temp = NULL;
    char *s = NULL;
    while (rd != 0){
        if (rd == -1) return NULL;
        temp = s;
        s = mx_strjoin(temp, &buff[0]);
        free(temp);
        rd = read(f, &buff[0], 1);
    }
    return s;
}

