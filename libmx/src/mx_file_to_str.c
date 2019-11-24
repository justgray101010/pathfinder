#include "libmx.h"

static char *file_cpy_to_str(char *string, const char *file) {
    int fd = 0;
    int sz = 0;
    char buffer;

    if ((fd = open(file, O_RDONLY)) == 0)
        return NULL;
    sz = read(fd, &buffer, 1);
    while (sz > 0) {
        string = mx_strjoin(string, &buffer);
        sz = read(fd, &buffer, 1);
    }
    close(fd);
    return string;
}

char *mx_file_to_str(const char *file) {
    int fd = 0;
    int sz = 0;
    int size = 0;
    char buffer;
    char *str;

    if ((fd = open(file, O_RDONLY)) == 0)
        return NULL;
    sz = read(fd, &buffer, 1);
    size++;
    while (sz > 0) {
        sz = read(fd, &buffer, 1);
        size++;
    }
    close(fd);
    str = mx_strnew(size);
    str = file_cpy_to_str(str, file);
    return str;
}
