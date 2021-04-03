#include "libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    int size_1 = mx_strlen(s1);
    int j = 0;
    int i = size_1;

    while (i < mx_strlen(s1) + mx_strlen(s2)) {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i++] = '\0';
    return s1;
}
