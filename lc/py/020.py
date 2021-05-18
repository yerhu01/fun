# Single DP
class Solution:
    def climbStairs(self, n: int) -> int:
        prev = 1
        prev_prev = 1
        for i in range(1, n):
            curr = prev + prev_prev
            prev_prev = prev
            prev = curr
        return prev

# 1D DP
class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0] * n
        dp[0] = 1

        for i in range(1, n):
            dp[i] = dp[i-1]
            dp[i] += dp[i-2] if i-2 >= 0 else 1
        return dp[-1]
