#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *p1 = dst;
    const char *p2 = src; // reinitializing type to be able to perform pointer arithmetic

    while (n > 0) {
        *p1 = *p2;
        p1++;
        p2++;
        n--;
    }
    return (dst);
}        
