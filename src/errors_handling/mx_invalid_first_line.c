#include "pathfinder.h"

void mx_invalid_first_line (file_data *path) {
    path->uniq_number_of_islands = mx_atoi(path->file_to_str);
    if (path->uniq_number_of_islands <= 0) {
        mx_printerr ("error: line 1 is not valid\n");
        mx_clean_memory_path(path);
        exit(1);
    }
}
