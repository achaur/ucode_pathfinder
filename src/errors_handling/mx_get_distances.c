#include "pathfinder.h"

static int my_atoi(char *s) {
    int i = 0;
    int output = 0;

    while (!mx_isdigit(s[i]))
        i++;
    while (mx_isdigit(s[i]))
        output = output * 10 + s[i++] - 48;
    return output;
}

void mx_get_distances(file_data *path) {

    char *buf = mx_strdup(path->file_to_str);
    int file_len = mx_strlen(path->file_to_str);
    int lines_count = mx_count_substr(path->file_to_str, "-");
    char **lineptr = mx_strsplit(buf, ',');
    int i, j = 0;
    
    for (i = 1; i <= mx_count_substr(path->file_to_str, "-"); i++, j++) {   
        path->routs[j] = my_atoi(lineptr[i]);
    }
    mx_strdel(&buf);
    mx_del_strarr(&lineptr);
}
