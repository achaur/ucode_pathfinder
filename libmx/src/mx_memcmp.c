#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const char *p1 = s1;
    const char *p2 = s2;

    while (*p1 == *p2 && n > 0) {
        p1++;
        p2++;
        n--;
    }
    return *p1 - *p2;
}
