#include "libmx.h"

int mx_clean_length (const char *str) {
    int count = 0;
    bool space = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!space || !mx_isspace(str[i])) 
            count++;
        space = mx_isspace(str[i]);
    }
  
    return count;
}

char *mx_del_extra_spaces(const char *str) {
    char *str_clean;
    int i;
    int j = 0;
    char *str_trim;
    bool space;

    if (!str)
        return NULL;
    str_trim = mx_strtrim(str);
  
    str_clean = mx_strnew(mx_clean_length(str_trim));

    if (!str_trim || !str_clean) 
        return NULL;
    space = false;
 
    for (i = 0; str_trim[i] != '\0'; i++) {
        if (!space || !mx_isspace(str_trim[i])) 
            str_clean[j++] = str_trim[i];
        space = mx_isspace(str_trim[i]);
    }
    mx_strdel(&str_trim);
    return str_clean;
}
