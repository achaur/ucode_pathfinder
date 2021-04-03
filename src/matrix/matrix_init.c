#include "pathfinder.h"

void matrix_init(matrix *matrix_path, file_data *path) {
    mx_get_words_and_routs(path);
    int i, j;
    int n = path->uniq_number_of_islands;
    int m = path->count_words + path->count_words / 2 + 1; 
    int k = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                matrix_path->distance[i][j] = 0;
            else 
                matrix_path->distance[i][j] = INT_MAX;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix_path->distance[i][j] == INT_MAX) {
                for(int c = 0; path->words_and_routs[c]; c++){
                    if (mx_strcmp(path->uniq_islands_names[i], path->words_and_routs[c]) == 0 &&
                        mx_strcmp(path->uniq_islands_names[j], path->words_and_routs[c + 1]) == 0) {
                        matrix_path->distance[i][j] = mx_atoi(path->words_and_routs[c + 2]);
                        matrix_path->distance[j][i] = mx_atoi(path->words_and_routs[c + 2]);
                    }
                }
            }    
        }   
    }
}
