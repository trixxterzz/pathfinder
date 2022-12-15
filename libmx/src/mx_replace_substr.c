#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace){
    if (str == NULL || sub == NULL || replace == NULL) return NULL;
    int newsize = mx_strlen(str) + ((mx_strlen(replace) - mx_strlen(sub)) * mx_count_substr(str, sub));
    char *newstr = mx_strnew(newsize);
    int str_ind = 0;
    int replace_ind = 0;
    int new_ind = 0;
    int ind = mx_get_substr_index(str, sub);
    if (ind == -1) return mx_strdup(str);
    char *buff = (char *)str;
    int iter_count = newsize + mx_count_substr(str, sub);
    for (int i = 0; i < iter_count; i++){
        if (new_ind < ind){
            newstr[new_ind] = buff[str_ind];
            str++;
            str_ind++;
            new_ind++;
        }
        else if (new_ind >= ind && new_ind < ind + mx_strlen(replace)){
            newstr[new_ind] = replace[replace_ind];
            replace_ind++;
            new_ind++;
        }
        else if (new_ind >= ind && new_ind >= ind + mx_strlen(replace)){
            for (int j = 0; j < mx_strlen(sub); j++) {
                str++;
                str_ind++;
            }
            ind = mx_get_substr_index(str, sub) + new_ind;
            replace_ind = 0;
            if (ind == -1) break; 
        }
    }
    return newstr;
}

