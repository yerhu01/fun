int characterReplacement(char * s, int k){
    int ret = 0;
    int slen = strlen(s);
    int cnt[26] = {0}, max_cnt = 0;
    for (int l = 0, r = 0; r < slen; ++r) {
        cnt[s[r]-'A'] += 1;
        max_cnt = (cnt[s[r]-'A'] > max_cnt) ? cnt[s[r]-'A'] : max_cnt;
        if (r-l+1-max_cnt > k) {
            cnt[s[l]-'A'] -= 1;
            ++l;
        } else 
            ret = (r-l+1 > ret) ? r-l+1 : ret;
    }
    return ret;
}
