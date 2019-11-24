#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2){
    char *conc_string = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    char *res = conc_string;

    while (*s1) {
        *conc_string = *s1;
        s1++;
        conc_string++;
    }
    while (*s2) {
        *conc_string = *s2;
        s2++;
        conc_string++;
    }
    return res;
}
