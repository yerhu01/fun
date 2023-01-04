

// with lookup
bool isValid(char *s){
    int i, len = strlen(s);
    char *st = malloc(len * sizeof(char));
    int top = 0;
    char *lookup = "(){}[]";
    
    for (i = 0; i < len; ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st[top++] = s[i];
        } else if (top == 0 || s[i] != lookup[(int)(strchr(lookup, st[--top]) - lookup) + 1]) {
            free(st);
            return false;
        }
    }
    free(st);
    return top == 0;
}

// with switch
bool isValid(char *s){
    int i, len = strlen(s);
    char *st = malloc(len * sizeof(char));
    int top = 0;
    for (i = 0; i < len; ++i) {
        switch (s[i]) {
            case '(':
                st[top++] = ')';
                continue;
            case '{':
                st[top++] = '}';
                continue;
            case '[':
                st[top++] = ']';
                continue;
        }
        if (top == 0 || s[i] != st[--top]) {
            free(st);
            return false;
        }
    }
    free(st);
    return top == 0;
}
