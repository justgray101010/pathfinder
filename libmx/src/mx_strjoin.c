#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 && s2) {
        int s1len = mx_strlen(s1);
        int s2len = mx_strlen(s2);
        char *joinedstr = mx_strnew(s1len + s2len);

        mx_strcpy(joinedstr, s1);
        mx_strcpy(joinedstr + s1len, s2);
        return joinedstr;
    }
    else if (s1)
        return (char *)s1;
    else if (s2)
        return (char *)s2;
    else
        return NULL;
}
