#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    t_list *current = lst; 
    t_list *index = NULL;
    void *tmp;
    
    while(current != NULL) {  
        index = current->next;            
        while(index != NULL) {  
            if(cmp(current->data, index->data)) {  
                tmp = current->data;  
                current->data = index->data;  
                index->data = tmp;  
            }  
            index = index->next;  
        }  
        current = current->next;  
    }     
    return lst;
}
