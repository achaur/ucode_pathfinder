#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *head_new = NULL;

    if (!head || !*head) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        head_new = (*head)->next;
        free(*head);
        *head = head_new;  
    }
}
