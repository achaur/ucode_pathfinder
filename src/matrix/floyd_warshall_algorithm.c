#include "pathfinder.h"

void floyd_warshall_algorithm(matrix *matrix_path, file_data *path) {
    int n = path->uniq_number_of_islands;
    int i;
    long sum;

    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix_path->table[i][j] = matrix_path->distance[i][j];   
        }
    }
    for (int k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                sum = matrix_path->distance[i][k] + matrix_path->distance[k][j];
                if (matrix_path->distance[i][j] > sum) {
                    matrix_path->distance[i][j] = sum;
                    matrix_path->distance[j][i] = sum;
                }
            }
        }
    }
}
