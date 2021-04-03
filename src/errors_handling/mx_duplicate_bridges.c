#include "pathfinder.h"

void mx_duplicate_bridges(file_data *path) {
    int n = path->count_words;

    for (int i = 0; i < n; i = i + 2) {
        for (int j = i + 2; j < n; j = j + 2) {
            if (mx_strcmp(path->words[i], path->words[j]) == 0 && 
                 mx_strcmp(path->words[i + 1], path->words[j + 1]) == 0) {
                     mx_printerr("error: duplicate bridges\n");
                     mx_del_strarr(&path->words);
                     mx_clean_memory_path(path);
                     exit(1);
            }
            if (mx_strcmp(path->words[i], path->words[j + 1]) == 0 && 
                 mx_strcmp(path->words[i + 1], path->words[j]) == 0) {
                     mx_printerr("error: duplicate bridges\n");
                     mx_del_strarr(&path->words);
                     exit(1);
            }
        }
    }
}
