#include "../inc/libmx.h"

int mx_strlen_spec(const char *s, char c){
    int i = 0;
    while (*s != '\0' || *s != c)
    {
        i++;
        s++;
    }
    return i;
}

char **mx_strsplit(const char *s, char c){
    if (s == NULL) return NULL;
    int size = mx_count_words(s, c);
    if (size == 0) return NULL;
    char **arr = malloc(sizeof(char *) * (size + 1));
    char *buff = (char *)s;
    int arr_ind = 0;
    while (*buff != '\0'){
        if (*buff != c && *buff != '\0'){
            int word_len = 0;
            char *start = buff;
            while (*buff != c && *buff != '\0'){
                buff++;
                word_len++;
            }
            arr[arr_ind] = mx_strnew(word_len);
            if (arr[arr_ind] == NULL) return NULL;
            arr[arr_ind] = mx_strncpy(arr[arr_ind], start, word_len);
            if (arr[arr_ind] == NULL) return NULL;
            arr_ind++;
        }
        else{
            buff++;
        }
        
    }
    arr[arr_ind] = NULL;
    return arr;
}

