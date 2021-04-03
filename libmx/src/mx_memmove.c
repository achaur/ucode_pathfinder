#include "libmx.h"
#include "stdio.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *p1 = dst;
    char *tmp = malloc(sizeof(char) * len);
    const char *p2 = src;

    for (size_t i = 0; i < len; i++) 
        tmp[i] = p2[i];
    for (size_t i = 0; i < len; i++) 
        p1[i] = tmp[i];
    free(tmp);

printf(" -- dst addr %p --\n", (void*)dst);
    return (dst);
}
