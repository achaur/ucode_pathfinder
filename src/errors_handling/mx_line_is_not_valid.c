#include "pathfinder.h"

void mx_line_is_not_valid(file_data *path) {
    mx_get_words(path);
    mx_get_uniq_islands(path);
    mx_get_distances(path);
}
