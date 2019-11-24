#include "libmx.h"

char *mx_strdup(const char *str) {
    char *newstr = mx_strnew(mx_strlen(str));
    return newstr ? mx_strcpy(newstr, str) : NULL;
}
