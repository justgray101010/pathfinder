#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *s1_char = (unsigned char *)s1;
    unsigned char *s2_char = (unsigned char *)s2;

    while (*s1_char && n-- > 0) {
        if (*s1_char != *s2_char)
            break;
        s1_char++;
        s2_char++;
    }
    return *s1_char - *s2_char;
}
