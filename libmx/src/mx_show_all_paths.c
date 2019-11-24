#include "libmx.h"

static void init(char ***s1, char ***s2, int number) {
    for (int i = 0; i < number; i++) {
            char **paths = (char**) malloc(sizeof(char*) * (number + 1));
            for (int j = 0; j <= number; j++) {
                paths[j] = NULL;
            }
            s1[i] = paths;
        }
        for (int i = 0; i < number; i++) {
            char **paths = (char**) malloc(sizeof(char*) * (number + 1));
            for (int j = 0; j <= number; j++) {
                paths[j] = NULL;
            }
            s2[i] = paths;
        }
}

static void init_path(int index_min, island **arr, int number, int *flags, int *d, char ***path, char ***dpath) {
    for (int i = 0; arr[index_min]->distance_between_islands[i] != 0 && i < number; i++) {
        int j = 0;
        for (; j < number; j++) {
            if (mx_strcmp(arr[j]->name, arr[index_min]->bridge_to_islands[i]) == 0)
                break;
            }
        if (flags[j] == 0) {
            if (d[j] == d[index_min] + (arr[index_min]->distance_between_islands[i])) {
                int k = 0;
                for (; path[index_min][k] != NULL; k++) {
                    dpath[j][k] = path[index_min][k];
                }
                dpath[j][k] = arr[j]->name;
            }
            if (d[j] > d[index_min] + (arr[index_min]->distance_between_islands[i])) {
                d[j] = d[index_min] + (arr[index_min]->distance_between_islands[i]);
                int k = 0;
                for (; path[index_min][k] != NULL; k++) {
                    path[j][k] = path[index_min][k];
                }
                path[j][k] = arr[j]->name;
            }
        }
    }
}

static void init_paths(int number, island **arr, int *flags, int *d, int max, char ***path, char ***dpath) {
    int check_flags = 0;
    while (check_flags != number) {
            check_flags = 0;
            int min = max;
            int index_min = 0;
            for (int i = 0; i < number; i++) {
                if (d[i] < min && flags[i] == 0) {
                    min = d[i];
                    index_min = i;
                }
            }
            flags[index_min] = 1;
            init_path(index_min, arr, number, flags, d, path, dpath);
            for (int k = 0; k < number; k++) {
                check_flags += flags[k];
            }
        }
}

static void init_dpaths(int number, char ***path, char ***dpath) {
    for (int c = 0; c < number; c++) {
            if (dpath[c][0] != NULL) {
                int last = 0;
                for (; dpath[c][last] != NULL; last++);
                last--;
                for (int org = 0; org < number; org++) {
                    int v = 0;
                    for (; path[org][v] != NULL; v++) {
                        if (mx_strcmp(path[org][v], dpath[c][last]) == 0) {
                            int left = 0;
                            for ( ;dpath[c][left] != NULL; left++)
                                dpath[org][left] = dpath[c][left];
                            for (int right = left; right < number; right++)
                                dpath[org][right] = path[org][right];
                        }
                    }
                }
            }
        }
}

void mx_show_all_paths(island **arr, int number, int max) {
    for (int isl = 0; isl < number; isl++) {
        int d[number];
        char ***dpath = (char***) malloc(sizeof(char**) * number);
        char ***path = (char***) malloc(sizeof(char**) * number);
        int flags[number];
        for (int i = 0; i < number; i++)
            d[i] = max;
        d[isl] = 0;
        for (int i = 0; i < number; i++)
            flags[i] = 0;
        init(dpath, path, number);
        init_paths(number, arr, flags, d, max, path, dpath);
        init_dpaths(number, path, dpath);
        for (int i = 0; i < number; i++) {
                char **temp_path = (char**) malloc(sizeof(char*) * (number + 1));
                temp_path = path[i];
                if (dpath[i][0] != NULL) {
                    path[i] = dpath[i];
                    mx_print_paths(i, isl, number, path, arr, d);
                }
                if (dpath[i][0] != NULL) {
                    path[i] = temp_path;
                }
                mx_print_paths(i, isl, number, path, arr, d);
        }
    }
}
