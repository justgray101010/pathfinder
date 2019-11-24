#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *s_char = (unsigned char *)s + n;

    while (*s_char) {
        if (*s_char == (unsigned char)c)
            return s_char;
        s_char--;
    }
    return NULL;
}
