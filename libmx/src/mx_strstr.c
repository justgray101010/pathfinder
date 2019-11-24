#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int needlen = mx_strlen(needle);

    while (*haystack) {
        if (mx_strncmp(haystack, needle, needlen) == 0) {
            char *temp = (char*)haystack;
            return temp;
        }
        haystack++;
    }
    return NULL;
}
