#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str && sub && replace) {
        int counter = 0;
        int strlen = mx_strlen(str);
        int sublen = mx_strlen(sub);
        int replacelen = mx_strlen(replace);
        for (int i = 0; i < strlen; i++) {
            if (mx_strncmp(str + i, sub, sublen) == 0)
                counter++;
        }
        char *newstr = mx_strnew(strlen - sublen * counter + replacelen * counter);
        char *temp = newstr;
        while (*str) {
            if (mx_strncmp(str, sub, sublen) == 0) {
                mx_strncpy(newstr, replace, replacelen);
                newstr += replacelen;
                str += sublen;
            } else {
                *newstr = *str;
                str++;
                newstr++;
            }
        }
        return temp;;
    }
    return NULL;    
}
