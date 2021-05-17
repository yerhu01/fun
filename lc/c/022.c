#define LEN 128

char * minWindow(char * s, char * t){
    int s_len = strlen(s), total = strlen(t);
    int t_count[LEN] = {0};
    int start = 0, end = INT_MAX;
    int l = 0, r = 0;

    for (int i = 0; i < total; ++i) t_count[t[i]] += 1;
    for (int i = 0; i < LEN; ++i ) {
        if (!t_count[i])
            t_count[i] = -s_len;
    }

    while (r < s_len) {
        if (t_count[s[r]] > 0)
            total -= 1;
        t_count[s[r]] -= 1;

        while (total == 0) {
            if (r-l+1 < end-start+1) {
                start = l; end = r;
            }
            t_count[s[l]] += 1;
            if (t_count[s[l]] > 0)
                total += 1;
            l++;
        }
        r++;
    }

    if(end != INT_MAX){
        s[end+1] = '\0';
        s += start;
        return s;
    }
    return "";
}
