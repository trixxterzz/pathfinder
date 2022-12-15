#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str){
    if (str == NULL) return NULL;
    int flag = 0;
    char *trimmed = mx_strtrim(str);
    int old_len = mx_strlen(trimmed);
    int new_len = old_len;
    for (int i = 0; i < old_len; i++){
        if (mx_isspace(trimmed[i]) == true && flag == 0){
            flag = 1;
        }
        else if (mx_isspace(trimmed[i]) == true && flag == 1){
            new_len--;
        }
        else if (mx_isspace(trimmed[i]) == false){
            flag = 0;
        }
    }
    char *new = mx_strnew(new_len);
    int new_ind = 0;
    for (int i = 0; i < old_len; i++){
        if (mx_isspace(trimmed[i]) == true && flag == 0){
            flag = 1;
            new[new_ind] = trimmed[i];
            new_ind++;
        }
        else if (mx_isspace(trimmed[i]) == true && flag == 1){
            continue;
        }
        else if (mx_isspace(trimmed[i]) == false){
            flag = 0;
            new[new_ind] = trimmed[i];
            new_ind++;
        }
    }
    mx_strdel(&trimmed);
    return new;
}

