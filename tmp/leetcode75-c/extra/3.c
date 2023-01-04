int integerBreak(int n){
    if (n == 2 || n == 3)
        return n-1;

    int exp = n/3;
    int remainder = n%3;
    if (remainder == 0)
        return pow(3, exp);
    if (remainder == 1) {
        exp -= 1;
        remainder = 4;
    }
    return pow(3, exp) * remainder;
}

int integerBreak(int n){
    if (n == 2 || n == 3)
        return n-1;

    int ret = 1;
    while (n > 4) {
        n -= 3;
        ret *= 3;
    }
    ret *= n;
    return ret;
}
