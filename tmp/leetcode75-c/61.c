int* countBits(int num, int* returnSize){
    int *ret = malloc((num+1)*sizeof(int));
    *returnSize = num+1;
    ret[0] = 0;
    int i = 0;
    for (int n = 1; n < num+1; ++n) {
        if ((n & (n-1)) == 0) // n is power of 2
            i = 0;
        ret[n] = ret[i] + 1;
        ++i;
    }
    return ret;
}
