#include "pathfinder.h"

void mx_all_errors (int argc, char *argv[], file_data *path) {
    mx_invalid_num_of_argc(argc, argv, path);
    mx_file_is_empty(argc, argv, path);
    mx_invalid_first_line (path);
    mx_line_is_not_valid(path);
    mx_invalid_number_of_islands(path);
    mx_duplicate_bridges(path);
    mx_sum_of_routs_is_too_big(path);
}
