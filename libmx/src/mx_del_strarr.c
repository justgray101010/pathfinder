#include "libmx.h"

void mx_del_strarr(char ***arr) {
    while (***arr != 0) {
        while (**arr != 0) {
            while (*arr != 0)
                mx_strdel(*arr);
        }
    }
}
