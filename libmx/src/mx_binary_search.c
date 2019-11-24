#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    unsigned long long left = 0;
    unsigned long long right = size - 1;
    int middle = 0;

    *(count) = 0;

    if (arr && size > 0 && s) {
        while (left <= right) {
            middle = left + (right - left) / 2;
            (*count)++;

            if (mx_strcmp(arr[middle], s) == 0)
                return middle;
            else if (mx_strcmp(arr[middle], s) > 0)
                right = middle - 1;
            else
                left = middle + 1;
        }
    }
    *(count) = 0;
    return -1;
}
