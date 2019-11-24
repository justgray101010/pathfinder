int mx_factorial_iter(int n) {
    unsigned long long r;

    if (n == 0)
        return 1;
    if (n > 0) {
        for (r = 1; n > 1; r *= n--) {
            if(r > 2147483647)
                return 0;
        }
        return r;
    }
    return 0;
}
