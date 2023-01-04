# Space optimized DP
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        lookup = [1]*n
        
        for row in range(m-1):
            for col in range(1,n):
                lookup[col] += lookup[col-1]
        
        return lookup[-1]

# Basic DP Tabulized
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        lookup = [[0]*n for _ in range(m)]
        
        for row in range(m): # num of paths to reach 1st col's is 1
            lookup[row][0] = 1
            
        for col in range(n): # num of paths to reach top col's is 1
            lookup[0][col] = 1
        
        for row in range(1, m):
            for col in range(1, n):
                lookup[row][col] = lookup[row-1][col] + lookup[row][col-1]
        
        return lookup[m-1][n-1]

# DP Memoized
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        def dfs(r, c):
            if r == 0 or c == 0:
                return 1
            
            if lookup[r][c] == 0:
                top = 0 if r == 0 else dfs(r-1, c)
                left = 0 if c == 0 else dfs(r, c-1)
                lookup[r][c] = top + left
            return lookup[r][c]
        
        lookup = [[0]*n for _ in range(m)]
        return dfs(m-1, n-1)

# Brute force => exponential time
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        def numPaths(m, n):
            if m == 1 or n == 1:
                return 1

            return numPaths(m-1, n) + numPaths(m, n-1)
        
        return numPaths(m,n)
