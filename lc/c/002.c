#define EMPTY 0x80808080

int lengthOfLongestSubstring(char * s){
    int ret = 0;
    int start = 0, slen = strlen(s);
    int prev[128];
    memset(prev, 0x80, sizeof prev);
    for (int i = 0; i < slen; ++i) {
        if (prev[s[i]] != EMPTY && prev[s[i]] >= start)
            start = prev[s[i]] + 1;
        prev[s[i]] = i;
        ret = i-start+1 > ret ? i-start+1 : ret;
    }
    return ret;
}
