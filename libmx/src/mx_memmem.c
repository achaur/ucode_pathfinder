#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    size_t i = 0, count, j;
    
    if (!big || big_len < little_len) return NULL;
    if (little_len == 0) return (void *)big;
    if (little_len < big_len && (big_len && little_len) > 0) {
        for (; big_len > 0; big_len--) {
        j = 0;
        count = 0;
            while (((unsigned char *)big)[i] == ((const unsigned char *)little)[j]) {   
                count++;
                i++;
                j++;  
            }
            if (count == little_len) {
                return &(((unsigned char *)big)[i - j]);
            }
            else
                i++;
        }   
    }
    return NULL;
}
