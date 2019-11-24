#include "libmx.h"

int mx_data_processing(island **arr, int n, const char *island1, const char *island2) {
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < n; i++) {
        if (mx_strcmp(island1, arr[i]->name) == 0) {
            flag1 = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (mx_strcmp(island2, arr[i]->name) == 0) {
            flag2 = 2;
        }
    }
    return flag1 + flag2;
}
