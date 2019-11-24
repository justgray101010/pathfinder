#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char *big_char = (unsigned char *)big;
    unsigned char *little_char = (unsigned char *)little;

    while (*big_char && big_len-- > 0) {
        if (mx_memcmp(big_char, little_char, little_len) == 0)
            return big_char;
        big_char++;
    }
    return NULL;
}
