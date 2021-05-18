# 1D DP
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [1] + [0] * (n-1)

        for _ in range(m):
            for c in range(1, n):
                dp[c] = dp[c] + dp[c-1]
        return dp[-1]

# 2D DP
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1

        for r in range(m):
            for c in range(n):
                top = dp[r-1][c] if r > 0 else 0
                left = dp[r][c-1] if c > 0 else 0
                dp[r][c] = dp[r][c] + top + left
        return dp[-1][-1]
