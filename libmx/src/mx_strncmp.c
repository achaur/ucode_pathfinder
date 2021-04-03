#include "libmx.h"

int mx_strncmp(const char *str1, const char *str2, size_t n) {
    while (n-- > 0) {
        if (*str1 == *str2 && str1 && str2) {
            str1++;
            str2++;
        }
        else return (unsigned const char *)str1 - (unsigned const char *)str2;
    }
    return 0;
}
