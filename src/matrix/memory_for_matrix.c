#include "pathfinder.h"

void memory_for_matrix(matrix *matrix_path, file_data * path) {
    int n = path->uniq_number_of_islands;

    matrix_path->distance = (long **) malloc(n * sizeof (long *));
    matrix_path->table = (long **) malloc(n * sizeof(long *));
    for (int i = 0; i < n; i++) {
        matrix_path->distance[i] = (long *) malloc(n * sizeof (long));
        matrix_path->table[i] = (long *) malloc(n * sizeof (long));
    }
}
