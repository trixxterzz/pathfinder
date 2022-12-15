#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)){
    int size = mx_list_size(lst);
    t_list *buff_list = lst;
    for (int i = 0; i < size; i++){
        buff_list = lst;
        int flag = 0;
        for (int j = 0; j < size - i; j++){
            t_list *temp = buff_list;
            t_list *temp_next = buff_list->next;
            if (cmp(temp->data, temp_next->data) == true){
                void *buff = temp->data;
                temp->data = temp_next->data;
                temp_next->data = buff;
            }
            temp = temp->next;
        }
        if (flag == 0) break;
    }
    return lst;
}

