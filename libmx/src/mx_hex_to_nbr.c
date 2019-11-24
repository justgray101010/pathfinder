#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if(hex == NULL)return 0;
    int len = mx_strlen(hex);
    unsigned long base = 1;
    unsigned long return_numb = 0;

    for(int i = len - 1; i >= 0; i--, base *= 16) {
        if (hex[i] >= '0' && hex[i] <= '9')
            return_numb += (hex[i] - 48) * base;
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            return_numb += (hex[i] - 55) * base;
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            return_numb += (hex[i] - 87) * base;
        else
            return 0;
    }
    return return_numb;
}

