static int expand(char *s, int l, int r) {
    int count = 0;
    int slen = strlen(s);
    while (l >= 0 && r < slen && s[l] == s[r]) {
        --l; ++r;
        count += 1;
    }
    return count;
}

int countSubstrings(char * s){
    int slen = strlen(s);
    int ret = 0;
    for (int i = 0; i < slen; ++i) {
        ret += expand(s, i, i);
        ret += expand(s, i, i+1);
    }
    return ret;
}
