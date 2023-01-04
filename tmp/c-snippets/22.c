// Optimized
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
        
        while (!total) {
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
        char *ret = malloc((end-start+2) * sizeof(*ret));
        *ret = '\0';
        strncat(ret,s+start, end-start+1);
        return ret;
    }
    return "";
}

// My solution
char * minWindow(char * s, char * t){
    int s_len = strlen(s), t_len = strlen(t), total = t_len;
    int t_count[128] = {0}, targ[128] = {0}, extra[128] = {0};
    int l = 0, r = 0;
    int start = -1, end = -1;
    for (int i = 0; i < t_len; ++i) {
        t_count[t[i]] += 1;
        targ[t[i]] = 1;
    }
    
    while (r < s_len) {
        if (targ[s[r]]) {
            if (t_count[s[r]] > 0) {
                t_count[s[r]] -= 1;
                total -= 1;
            } else {
                extra[s[r]] += 1;
            }
        }
        
        while (!total) {
            if (start == -1 || r-l+1 < end-start+1) {
                start = l;
                end = r;
            }
            if (targ[s[l]]) {
                if (extra[s[l]] > 0) {
                    extra[s[l]] -= 1;
                } else {
                    t_count[s[l]] += 1;
                    total += 1;
                }
            }
            l += 1;
        }
        r += 1;
    }
    
    if (start != -1) {
        char *ret = malloc((end-start+2) * sizeof(*ret));
        strncpy(ret, &s[start], end-start+1 );
        ret[end-start+1] = '\0';
        return ret;
    } 
    return "";
}
