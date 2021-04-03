#include "pathfinder.h"

int main(int argc, char *argv[]) {
    file_data *path = (file_data *)(malloc(sizeof(file_data)));
    matrix *matrix_path = (matrix *)malloc(sizeof(matrix));
    mx_all_errors(argc, argv, path);
    memory_for_matrix(matrix_path, path);
    matrix_init(matrix_path, path);
    floyd_warshall_algorithm(matrix_path, path);
    mx_print_output(path, matrix_path);
    // mx_del_strarr(&path->uniq_islands_names);
    // mx_del_strarr(&path->words);
    // mx_del_strarr(&path->words_and_routs);
    // mx_clean_memory_matrix(path, matrix_path);
    // mx_clean_memory_path(path);
    // system("leaks -q pathfinder");
    return 0;
}
