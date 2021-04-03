#include "pathfinder.h"

void mx_invalid_num_of_argc(int argc, char *argv[], file_data *path) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    path->fd = open(argv[1], O_RDONLY);
    path->file_to_str = NULL;
    if (path->fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        mx_clean_memory_path(path);
        exit(1);
    }
}
