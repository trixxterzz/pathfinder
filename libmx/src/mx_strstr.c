#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle){
    int length2 = mx_strlen(needle);
    char *cursor = mx_strchr(haystack, *needle);
    if (cursor == NULL){
        return NULL;
    }
    while (mx_strncmp(cursor, needle, length2) != 0){
        cursor = mx_strchr(cursor, *needle);
        if (cursor == NULL){
            return NULL;
        }
        cursor++;
    }
    if (mx_strncmp(cursor, needle, length2) == 0){
        return cursor;
    }
    return NULL;
}

