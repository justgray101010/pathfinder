#include "libmx.h"

void mx_sort_arr_int(int *arr, int size) {
    bool flag = true;
    int temp;

    while(flag) {
        flag = false;
        for(int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = true;
            }
        }
    }
}
