#include "../inc/libmx.h"

int mx_list_size(t_list *list){
    if (list == NULL) return 0;
    int size = 1;
    t_list *buff = list;
    while (buff->next != NULL){
        buff = buff->next;
        size++;
    }
    return size;
}

