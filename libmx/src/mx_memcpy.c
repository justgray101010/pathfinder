#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *dest_char = (char *)dst;
    char *src_char = (char *)src;

    for (size_t i = 0; i < n; i++)
        dest_char[i] = src_char[i];
    return dest_char;
}
