#include "libmx.h"

char *mx_strtrim(const char *str) {
    char *str_trim;
    int start;
    int end;
    int i;

    if (!str) 
        return NULL;
    for (i = 0; mx_isspace(str[i]); i++);
    start = i;
    for (i = mx_strlen(str) - 1; mx_isspace(str[i]); i--);
    end = i;
    if(end < 0)
        end = start;
    str_trim = mx_strnew(end - start + 1);
    if (!str_trim) 
        return NULL;
    for (i = start; i <= end; i++)
        str_trim[i - start] = str[i];
    // str_trim[i+1] = '\0';
    return str_trim;
}
