int mx_strlen(const char *c) {
    int i = 0;

    while (*c++)
        i++;
    return i;
}
