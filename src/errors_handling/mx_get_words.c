#include "pathfinder.h"

void mx_get_words(file_data *path) {
    int file_len = mx_strlen(path->file_to_str);
    int words_count = mx_count_substr(path->file_to_str, "-") * 2;
    path->count_words = words_count;
    int k = 0, m = 0;

    char *buf = mx_strdup(path->file_to_str);
    for (; buf[m] != '\0'; m++) {
        if (buf[m] == ',' ||  mx_isdigit(buf[m]) || buf[m] == '\n') {
            buf[m] = '-';
        }
    }
    path->words = mx_strsplit(buf, '-');
    mx_strdel(&buf);
}
