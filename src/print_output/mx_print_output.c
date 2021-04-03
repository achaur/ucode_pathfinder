#include "pathfinder.h"

static void print_shortest_path(file_data *path, matrix *matrix_path);
static bool check_shortest_path(file_data *path, matrix *matrix_path, int k);
static void print_path_and_route(file_data *path, matrix *matrix_path);
static void print_distance(file_data *path, matrix *matrix_path);

void mx_print_output(file_data *path, matrix *matrix_path) {
    for (int i = 0; i < path->uniq_number_of_islands; i++) {
        for (int j = i + 1; j < path->uniq_number_of_islands; j++) {
            matrix_path->route = (int *)malloc(sizeof(int) * (path->uniq_number_of_islands));
            matrix_path->len = 1;
            matrix_path->route[0] = j;
            matrix_path->route[matrix_path->len] = i;
            print_shortest_path(path, matrix_path);
            free(matrix_path->route);
        }
    }
}

static void print_shortest_path(file_data *path, matrix *matrix_path) {
    for (int k = 0; k < path->uniq_number_of_islands; k++) {
        if (k != matrix_path->route[matrix_path->len]
            && check_shortest_path(path, matrix_path, k)) {
            matrix_path->route[++matrix_path->len] = k;
            print_shortest_path(path, matrix_path);
            matrix_path->len--;
        }
    }
    if (matrix_path->route[matrix_path->len] != matrix_path->route[0])
        return;
    print_path_and_route(path, matrix_path);
    print_distance(path, matrix_path);
}

static bool check_shortest_path(file_data *path, matrix *matrix_path, int k) {
    int i = matrix_path->route[matrix_path->len];
    int j = matrix_path->route[0];

    if (matrix_path->table[i][k] == matrix_path->distance[i][j] - matrix_path->distance[k][j])
        return true;
    return false;
}

static void print_path_and_route(file_data *path, matrix *matrix_path) {
    mx_print_upper_boundary();
    mx_printstr("Path: ");
    mx_printstr(path->uniq_islands_names[matrix_path->route[1]]);
    mx_printstr(" -> ");
    mx_printstr(path->uniq_islands_names[matrix_path->route[matrix_path->len]]);
    mx_printstr("\n");
    mx_printstr("Route: ");
    for (int i = 1; i < matrix_path->len + 1; ) {
        mx_printstr(path->uniq_islands_names[matrix_path->route[i]]);
        ++i < matrix_path->len + 1 ? mx_printstr(" -> ") : mx_printstr("");
    }
    mx_printstr("\n");
}

static void print_distance(file_data *path, matrix *matrix_path) {
    int sum = 0;

    mx_printstr("Distance: ");
    for (int i = 1; i < matrix_path->len; i++){
        mx_printint(matrix_path->table[matrix_path->route[i]][matrix_path->route[i + 1]]);
        sum += matrix_path->table[matrix_path->route[i]][matrix_path->route[i + 1]];
        if (i < matrix_path->len - 1)
            mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);
        }
    }
    mx_printstr("\n");
    mx_print_upper_boundary();
}
