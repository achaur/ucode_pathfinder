#include "libmx.h"

char *mx_strdup(const char *str) {
    char *strcpy = mx_strnew(mx_strlen(str));

    mx_strcpy(strcpy,str);
    return strcpy;
}
