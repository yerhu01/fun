# DP Tabulation
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        
        lookup = [ 0 for _ in range(n+1) ]
        lookup[1] = 1
        lookup[2] = 2
        for i in range(3, n+1):
            lookup[i] = lookup[i-1] + lookup[i-2]
        return lookup[n]

# DP Memoized (similar to brute force)
class Solution:
    def climbStairs(self, n: int) -> int:
        lookup = [0]*(n+1)
        def dfs(i):
            if i == 0:
                return 1
            if i < 0:
                return 0
            if lookup[i] > 0:
                return lookup[i]
            lookup[i] = dfs(i-1) + dfs(i-2)
            return lookup[i]
            
        dfs(n)
        return lookup[n]

# Brute Force
class Solution:
    def climbStairs(self, n: int) -> int:
        def dfs(i):
            if i == 0:
                return 1
            if i < 0:
                return 0
            return dfs(i-1) + dfs(i-2)
            
        return dfs(n)
