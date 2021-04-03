#include "pathfinder.h"

void mx_invalid_number_of_islands(file_data *path) {

    if (path->uniq_number_of_islands != path->num_of_uniq_names) {
        mx_printerr("error: invalid number of islands\n");
        mx_del_strarr(&path->uniq_islands_names);
        mx_del_strarr(&path->words);
        mx_del_strarr(&path->words_and_routs);
        mx_clean_memory_path(path);
        exit(1);
    }
}
