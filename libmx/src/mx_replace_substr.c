#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *output = NULL;
    int count_sub = mx_count_substr(str, sub);
    int i = 0, j = 0;

    if (!str || !sub || !replace) return NULL;
    output = mx_strnew(mx_strlen(str) + ((mx_strlen(replace)) - (mx_strlen(sub))) * count_sub);
    for (; str[j]; ) {
        if (mx_strncmp(&str[j], sub, mx_strlen(sub)) == 0) {
            mx_strcat(output, replace);
            i += mx_strlen(replace);
            j += mx_strlen(sub);
        }
        else
            output[i++] = str[j++];
    }
    return output;
}
