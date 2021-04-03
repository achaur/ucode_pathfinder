#include "pathfinder.h"

static void del_int_arr(int **arr, file_data *path) {
    if (arr) {
        for (int i = 0; i < path->uniq_number_of_islands; i++)
            free(arr[i]);
        free(arr);
    }
}

void mx_clean_memory_matrix(file_data *path, matrix *matrix_path) {
    del_int_arr((int **)matrix_path->table, path);
    del_int_arr((int **)matrix_path->distance, path);
    free(matrix_path);
}
