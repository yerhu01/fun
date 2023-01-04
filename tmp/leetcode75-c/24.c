int numDecodings(char * s){
    int prev = 0, ret = 1;
    for (int i = 0; i < strlen(s); ++i) {
        int cur = 0;
        if (s[i] != '0')
            cur += ret;
        if (i > 0) {
            int val = (s[i-1]-'0')*10 + s[i]-'0';
            if (10 <= val && val <= 26)
                cur += prev;
        }
        if (cur == 0)
            return 0;
        prev = ret; ret = cur;
    }
    return ret;
}
