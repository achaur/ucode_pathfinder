#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    int i = 0;

    if (!str) return -2;
    for (; str[i] != '\0'; i++) {
        if (str[i] == c) return i;
    } 
    return -1;
}
