#include "libmx.h"

static void base_print(island **arr, int isl, char ***path, int i, int j) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(arr[isl]->name);
    mx_printstr(" -> ");
    mx_printstr(path[i][j]);
    mx_printstr("\n");
    mx_printstr("Route: ");
    mx_printstr(arr[isl]->name);
    mx_printstr(" -> ");
    mx_print_strarr(path[i], " -> ");
    mx_printstr("Distance: ");
}

static void print_distance(int t, int len, int number, char ***path, int i, island **arr, int *d, int isl) {
    for (t = 0; t < len; t++) {
        int k = 0;
        for (; k < number; k++) {
            if (mx_strcmp(path[i][t], arr[k]->name) == 0)
                break;
            }
            if (t == 0) {
                int n = 0;
                for (; n < number; n++) {
                    if (mx_strcmp(arr[k]->bridge_to_islands[n], arr[isl]->name) == 0) {
                        mx_printint(arr[k]->distance_between_islands[n]);
                        break;
                    }
                }
            } else {
                int n = 0;
                int ke = 0;
                for (; ke < number; ke++) {
                    if (mx_strcmp(path[i][t-1], arr[ke]->name) == 0)
                        break;
                }
                for (; n < number; n++) {
                    if (mx_strcmp(arr[k]->bridge_to_islands[n], arr[ke]->name) == 0) {
                        mx_printint(arr[k]->distance_between_islands[n]);
                            break;
                    }
                }
            }
            if (t + 1 != len) {
                mx_printstr(" + ");
            } 
    }
    mx_printstr(" = ");
    mx_printint(d[i]);
}

void mx_print_paths(int i, int isl, int number, char ***path, island **arr, int *d) {
    if (i > isl) {
        int j = 0, t = 0, len = 0;
        for (; j < number; j++) {
            if (path[i][j+1] == NULL)
                break;
        }
        base_print(arr, isl, path, i, j);                
        while (path[i][t] != NULL) {
            len++;
            t++;
        }
        if (len == 1) {
            mx_printint(d[i]);
        } else {
            print_distance(t, len, number, path, i, arr, d, isl);             
        }
        mx_printstr("\n");
        mx_printstr("========================================\n");
    }
}
