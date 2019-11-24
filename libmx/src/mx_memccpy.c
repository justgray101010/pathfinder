#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *dst_char = (unsigned char *)dst;
    unsigned char *src_char = (unsigned char *)src;

    if (src_char[0] == (unsigned char)c)
        return NULL;

    for (size_t i = 0; i < n; i++) {
        if (src_char[i] == (unsigned char)c) {
            dst_char[i] = src_char[i];
            return dst_char;
        }
        else
            dst_char[i] = src_char[i];
    }
    return dst_char;
}
