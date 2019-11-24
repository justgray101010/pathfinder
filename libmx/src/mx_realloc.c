#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *ptr_char;
    
    if (ptr == NULL) {
        return ptr_char = malloc(size);
    }
    else {
        ptr_char = malloc(size);
        if (ptr_char == NULL)
            return NULL;
        mx_memcpy(ptr_char, ptr, size);
        free(ptr);
    }
    return ptr_char;
}
