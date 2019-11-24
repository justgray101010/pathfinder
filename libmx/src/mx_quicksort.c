#include "libmx.h"

int mx_quicksort(char **arr,int left,int right){
    if(!arr)
        return -1;
    int count = 0;
    if (left >= right) return count;
    int leftI = left;
    int rightI = right;
    char *pivot = arr[left + (right - left)/2];
    while (leftI <= rightI) {
        while (mx_strlen(arr[leftI])  < mx_strlen(pivot)) leftI++;
        while (mx_strlen(arr[rightI]) > mx_strlen(pivot)) rightI--;
        if (leftI <= rightI) {
            if (mx_strcmp(arr[leftI], arr[rightI]) != 0){
                char *temp = arr[leftI];
                arr[leftI] = arr[rightI];
                arr[rightI] = temp;
                count++;
            }
            leftI++;
            rightI--;
        }
    }
    if(left < rightI)
        count += mx_quicksort(arr,left,rightI);
    if(leftI < right)
        count += mx_quicksort(arr,leftI,right);
    return count;
}

