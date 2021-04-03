#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *tmp = NULL;
    int count = 0;

    if (!list)
        return count;
    else {
        tmp = list;
        while (tmp) {
            count++;
            tmp = tmp->next;
        }
    } 
    return count;
}
