#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *p = (const unsigned char *)s;

    for (; n > 0; n--, p++) {
        if (*p == c) 
            return (void *)p;
    }
    return NULL;
}
