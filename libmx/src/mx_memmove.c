#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *cto = (char *)dst;
    char *cfrom = (char *)src;
    char *temp = (char *)malloc(len);

    for(unsigned long i = 0; i < len; i++)
        temp[i] = cfrom[i];
    for(unsigned long i = 0; i < len; i++)
        cto[i] = temp[i];
    free(temp);
    return dst;
}
