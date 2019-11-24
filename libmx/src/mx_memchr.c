#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *s_char = (unsigned char *)s;

    while (*s_char && n-- > 0) {
        if (*s_char == (unsigned char)c)
            return s_char;
        s_char++;
    }
    return NULL;
}
