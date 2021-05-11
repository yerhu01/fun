bool isValid(char *s){
    int len = strlen(s), top = 0;
    char st[len];
    memset(st, 0, sizeof st);
    char lookup[128] = {['('] = ')', ['{'] = '}', ['['] = ']'};

    for (int i = 0; i < len; ++i) {
        if (lookup[s[i]])
            st[top++] = s[i];
        else if (top == 0 || lookup[st[--top]] != s[i])
            return false;
    }
    return top == 0;
}
