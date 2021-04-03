#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    char *output;

    if (s1 == NULL && s2 == NULL) 
        return NULL;
    else if (s1 == NULL)
        return mx_strdup(s2);
    else if (s2 == NULL)
        return mx_strdup(s1);
    else {
        output = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        output = mx_strcat(mx_strcpy(output, s1), s2);
        return output;
    }
}
