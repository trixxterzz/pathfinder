#include "../inc/libmx.h"

void mx_pop_back(t_list **head){
    if (head == NULL || *head == NULL) return;
    t_list *buff = *head;
    while (buff->next->next != NULL){
        buff = buff->next;
    }
    free(buff->next);
    buff->next = NULL;
}

