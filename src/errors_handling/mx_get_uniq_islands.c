#include "pathfinder.h"

void mx_get_uniq_islands(file_data *path) {
    int i, j;
    int n = path->count_words;
    
    char **tmp = (char **)malloc(sizeof(char *) * (path->count_words + 1));
    tmp[path->count_words] = NULL;
    for (int k = 0; k < n; k++){
        tmp[k] = mx_strdup(path->words[k]);
     }   
    for (i = 0; i < n; i++) {
        j = i + 1;
        while (j < n) {
            if (mx_strcmp(tmp[i], tmp[j]) == 0) {
            mx_strcpy(tmp[j], tmp[n - 1]);
            n--;
            }
            else 
                j++;
        }
    }
    path->uniq_islands_names = (char **)malloc(sizeof(char *) * path->uniq_number_of_islands);
    for (i = 0; i < path->uniq_number_of_islands; i++) {
        path->uniq_islands_names[i] = mx_strdup(tmp[i]);
    }
    path->num_of_uniq_names = n;
    mx_del_strarr(&tmp);
}
