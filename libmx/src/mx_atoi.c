#include "libmx.h"

static bool mx_isdigit(char c) {
    if (c > 47 && c < 58)
        return true;
    return false;
}

static bool mx_isspace(char c) {
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
        return true;
    return false;
}

int mx_atoi(const char *str) {
    int i = 0;
    int n = 0;
    int s = 1;
    while (!mx_isdigit(str[i])){
        if (!mx_isspace(str[i]) && str[i] != '-' && str[i] != '+')
            return 0;
        i++;
    }
    if (str[i - 1] == '-') {
        s = -s;
    }
    for (; mx_isdigit(str[i]); i++) {
        n = ((n * 10) + (str[i] - '0'));
    }
    if (s < 0)
        n = -n;
    return n;
}
