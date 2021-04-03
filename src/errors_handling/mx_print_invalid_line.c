#include "pathfinder.h"

void mx_print_invalid_line(int line, file_data *path) {
    char *print = mx_itoa(line);

    mx_printerr("error: line ");
    mx_printerr(print);
    mx_printerr(" is not valid\n");
    mx_clean_memory_path(path);
    mx_strdel(&print);
    exit(1); 
}
