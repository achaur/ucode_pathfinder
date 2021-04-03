#include "pathfinder.h"

void mx_sum_of_routs_is_too_big(file_data *path) {
    long sum = 0;
    
    for (int i = 0; i < path->count_words / 2; i++)
        sum += path->routs[i];
    if (sum > INT_MAX) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        mx_del_strarr(&path->uniq_islands_names);
        mx_del_strarr(&path->words);
        mx_clean_memory_path(path);
        exit(1);
    }
}
