#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *node = mx_create_node(data);
    t_list *head = *list;

    node->next = head;
    *list = node;
}

// typedef struct s_list {
//     void *data;
//     struct s_list *next;
// }                t_list;
