#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    if (fd < 0) return -1;
    char *line = *lineptr;
    char buf[1];
    buf_size = 0;
    int k = 0;
    int i = 0;
    int n = read(fd, buf, 1);
    while (n != 0) {
        if (buf[0] == delim) {
            line[i] = '\0';
            return k;
        }
        line[i++] = buf[0];
        k++;
        n = read(fd, buf, 1);
    }
    line[i] = '\0';
    return k;
}
