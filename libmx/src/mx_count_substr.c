#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int counter = 0;
    int sublen;

    if (str && sub) {
        sublen = mx_strlen(sub);
        while (*str) {
            if (mx_strncmp(str, sub, sublen) == 0){
                counter++;
            }
            str++;
            
        }
    }

    if (counter > 0)
        return counter;
    else
        return -1;
}
