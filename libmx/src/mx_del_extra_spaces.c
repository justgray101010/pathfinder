#include "libmx.h"

static bool mx_isspace(char c) {
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
        return true;
    return false;
}

char *mx_del_extra_spaces(const char *str) {
    char *trimed = mx_strtrim(str);
    char *newstr = mx_strnew(mx_strlen(trimed));
    char *rez = newstr;
    while(*trimed) {
        while (mx_isspace(*trimed) && mx_isspace(*(trimed + 1))) {
            trimed++;
        }
        if (mx_isspace(*trimed) == true){
            *newstr++ = ' ';
            trimed++;
        } else 
        *newstr++ = *trimed++;
    }
    return mx_strtrim(rez);
}
