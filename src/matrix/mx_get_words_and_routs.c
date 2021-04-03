#include "pathfinder.h"

void mx_get_words_and_routs(file_data *path) {
    char *buf = mx_strdup(path->file_to_str);
    for (int i = 0; i < mx_strlen(buf); i++) {
        if (buf[i] == ',' || buf[i] == '\n')
            buf[i] = '-';
    }
    path->words_and_routs = mx_strsplit(buf, '-');
    mx_strdel(&buf);
}
