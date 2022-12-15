#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd){
    if (buf_size < 0 || fd < 0){
        return -2;
    }
    char buff[1];
    (*lineptr) = mx_realloc(*lineptr, buf_size);
    if (read(fd, &buff, 1)){
        if (buff[0] == delim){
            return 1;
        }
    }
    return 2;
}

