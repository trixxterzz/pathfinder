#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data){
    if (list == NULL) return;
    t_list *node = mx_create_node(data);
    if (*list == NULL) {
        *list = node;
        return;
    }
    t_list *curs = *list;
    while (curs->next != NULL){
        curs = curs->next;
    }
    curs->next = node;
}

