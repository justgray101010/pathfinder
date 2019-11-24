#include "libmx.h"

void mx_printchar(char c) {
    if (c)
        write(1, &c, 1);
}
