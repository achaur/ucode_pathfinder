#include "pathfinder.h"

void mx_clean_memory_path(file_data *path) {
    if (path->file_to_str)
        mx_strdel(&path->file_to_str);
    free(path);
}
