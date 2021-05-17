// Hash Table
bool isAnagram(char * s, char * t){
    int slen = strlen(s), tlen = strlen(t);
    if (slen != tlen)
        return false;

    int cnt[128] = {0};
    for (int i = 0; i < slen; ++i) {
        cnt[s[i]] += 1;
        cnt[t[i]] -= 1;
    }

    for (int i = 0; i < 128; ++i) {
        if (cnt[i] != 0)
            return false;
    }
    return true;
}

// Sorting
static int compare(void *a, void *b) {
    return *(char*)a - *(char*)b;
}

bool isAnagram(char * s, char * t){
    if (strlen(s) != strlen(t))
        return false;

    qsort(s, strlen(s), sizeof *s, compare);
    qsort(t, strlen(t), sizeof *t, compare);
    return strcmp(s, t) == 0 ? true : false;
}
