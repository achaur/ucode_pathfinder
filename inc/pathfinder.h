#pragma once

#include "libmx.h"
#include "stdio.h"


#define INT_MAX 2147483647 
#define INT_MIN -2147483648

typedef struct t_file_data {
    char *file_to_str;
    char **words;
    int *routs;
    char **words_and_routs;
    int fd; 
    int count_words;
    int uniq_number_of_islands;
    char **uniq_islands_names;
    int **next;
    int num_of_uniq_names;
    // char **uniq_islands_names1;
} file_data;

typedef struct matrix {
    int len;
    int *route;
    long **distance;
    long **table;
} matrix;

/*printing output*/
void mx_print_upper_boundary(void);
void mx_print_output(file_data *path, matrix *matrix_path);

/*errors handling*/
void mx_print_invalid_line(int line, file_data *path);
void mx_all_errors (int argc, char *argv[], file_data *path);
void mx_invalid_num_of_argc(int argc, char *argv[], file_data *path);
void mx_file_is_empty(int argc, char *argv[], file_data *path);
void mx_invalid_number_of_islands (file_data *path);
void mx_sum_of_routs_is_too_big (file_data *path);
void mx_duplicate_bridges (file_data *path);
void mx_clean_memory_path(file_data *path);
void mx_clean_memory_matrix(file_data *path, matrix *matrix_path);
void mx_invalid_first_line (file_data *path);
void mx_line_is_not_valid(file_data *path);
void mx_print_invalid_line(int line, file_data *path);

/*parsing*/
void mx_get_words(file_data *path);
void mx_get_distances(file_data *path);
void matrix_init(matrix *matrix_path, file_data *path);
void parse(file_data * path, char *argv[]);
void mx_get_uniq_islands(file_data *path);
void mx_get_words_and_routs(file_data *path);
void memory_for_matrix(matrix *matrix_path, file_data * path);

/*warshall-floyd-algorithm*/
void floyd_warshall_algorithm(matrix *matrix_path, file_data *path);
