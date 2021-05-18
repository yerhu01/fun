// 1D DP
int uniquePaths(int m, int n){
    int dp[n];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for (int r = 0; r < m; ++r) {
        for (int c = 1; c < n; ++c)
            dp[c] += dp[c-1];
    }
    return dp[n-1];
}

// 2D DP
int uniquePaths(int m, int n){
    int dp[m][n];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            int top = r > 0 ? dp[r-1][c] : 0;
            int left = c > 0? dp[r][c-1] : 0;
            dp[r][c] = dp[r][c] + top + left;
        }
    }
    return dp[m-1][n-1];
}
