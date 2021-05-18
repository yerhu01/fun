// Single DP
int climbStairs(int n){
    int prev = 1, prev_prev = 1;
    for (int i = 1; i < n; ++i) {
        int curr = prev + prev_prev;
        prev_prev = prev;
        prev = curr;
    }
    return prev;
}

// 1D DP
int climbStairs(int n){
    int dp[n];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i-1];
        dp[i] += i-2 >= 0 ? dp[i-2] : 1;
    }
    return dp[n-1];
}
