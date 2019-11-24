#include "libmx.h"

static bool mx_isspace(char c) {
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
        return true;
    return false;
}

char *mx_strtrim(const char *str) {
    int strlen = mx_strlen(str) - 1;
    int i = 0;
    char *endstr;

    while (mx_isspace(str[i]) && i < strlen + 1)
        i++;
    while (mx_isspace(str[strlen]) && strlen >= 0) {
        strlen--;
    }

    endstr = mx_strnew(strlen - i + 1);
    mx_strncpy(endstr, str + i, strlen - i + 1);
    mx_strncpy(endstr, str + i, strlen - i + 1);
    return endstr;
}
