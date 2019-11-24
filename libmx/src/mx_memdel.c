#include "libmx.h"

void mx_memdel(void **ar) {
    if (ar) {
        free(*ar);
        *ar = NULL;
    }
}
