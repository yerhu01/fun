static int expand(char *s, int l, int r) {
    int slen = strlen(s);
    while (l >= 0 && r < slen && s[l] == s[r]) {
        --l; ++r;
    }
    return r-l-1;
}

char * longestPalindrome(char * s){
    if (!s)
        return "";

    int l = 0, r = 0;
    int slen = strlen(s);
    for (int i = 0; i < slen; ++i) {
        int len1 = expand(s, i, i);
        int len2 = expand(s, i, i+1);
        int length = (len1 > len2) ? len1 : len2;
        if (length > r-l+1) {
            l = i - (length-1)/2;
            r = i + length/2;
        }
    }
    s = s+l;
    s[r-l+1] = '\0';
    return s;
}
