bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int dplen = strlen(s)+1;
    int dp[dplen];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < strlen(s); ++i) {
        if (dp[i]) {
            for (int w = 0; w < wordDictSize; ++w) {
                int wlen = strlen(wordDict[w]);
                if (i+wlen < dplen && strncmp(&s[i], wordDict[w], wlen) == 0)
                    dp[i+wlen] += 1;
            }
        }
    }
    return dp[dplen-1] ? true : false;
}
