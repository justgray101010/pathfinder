int mx_sqrt(int x) {
	unsigned long left = 1;
    unsigned long right = x;
    unsigned long middle = 0;
    unsigned long result;
if(x == 1){
    return 1;
}
    while (right - left > 0) {
        middle = left + (right - left) / 2;
        result = middle * middle;

        if (result == (unsigned long)x)
            return middle;
        else if (result > (unsigned long)x)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return 0;
}
