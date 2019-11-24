#include "libmx.h"

static bool mx_isdigit(char c) {
    if (c > 47 && c < 58)
        return true;
    return false;
}

static int get_islands_number(char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        write(2, "error: file ", mx_strlen("error: file "));
        write(2, argv[1], mx_strlen(argv[1]));
        write(2, " doesn't exist\n", mx_strlen(" doesn't exist\n"));
        exit(1);
    }
    char *firstline = (char*) malloc(sizeof(char)*12);
    int bytes = mx_read_line(&firstline, 4, '\n', fd);
    if (bytes == 0) {
        write(2, "error: file ", mx_strlen("error: file "));
        write(2, argv[1], mx_strlen(argv[1]));
        write(2, " is empty\n", mx_strlen(" is empty\n"));
        exit(1);
    }
    for (int i = 0; i < mx_strlen(firstline); i++) {
        if (mx_isdigit(firstline[i]) == false){
            write(2, "error: line 1 isn't valid\n", mx_strlen("error: line 1 isn't valid\n"));
            exit(1);
        }
    }
    return mx_atoi(firstline);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "usage: ./pathfinder [filename]\n", mx_strlen("usage: ./pathfinder [filename]\n"));
        exit(1);
    }
    int number = get_islands_number(argv);
    island **arr = (island**) malloc(sizeof(island*) * number);
    for (int i = 0; i < number; i++) {
        island *temp = (island*) malloc(sizeof(island));
        temp->name = (char*) malloc(sizeof(char) * 50);
        temp->bridge_to_islands = (char**) malloc(sizeof(char*) * (number + 1));
        temp->distance_between_islands = (int*) malloc(sizeof(int) * (number));
        arr[i] = temp;
    }
    int max_distance = mx_get_island_arr(arr, number, argv);
    for (int t = 0; t < number; t++) {
        if (arr[t]->name[0] == '\0') {
            write(2, "error: invalid number of islands\n", mx_strlen("error: invalid number of islands\n"));
            exit(1);
        }
    }
    mx_show_all_paths(arr, number, max_distance);
    return 0;
}
