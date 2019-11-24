#include "libmx.h"

static void mx_printnum(int num) {
    if(num > 9)
        mx_printnum(num / 10);
    mx_printchar(num % 10 + 48);
}

void mx_printint(int n) {
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if(n < 0) {
        mx_printchar('-');
        n *= -1;
    }
    mx_printnum(n);
}
