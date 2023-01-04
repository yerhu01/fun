# Bottom up DP Space Optimized
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        min_coins = [0] + [float('inf')] * amount
        
        for c in range(1, amount+1):
            for coin in coins:
                if c - coin >= 0 and min_coins[c-coin] < float('inf'):
                    min_coins[c] = min(min_coins[c], 1+min_coins[c-coin])

        return min_coins[amount] if min_coins[amount] < float('inf') else -1

# Bottom up DP EPI 16.1 variation
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        min_coins = [[0] + [float('inf')] * amount for _ in range(len(coins))]
        
        for r in range(len(coins)):
            for c in range(1, amount+1):
                without_coin = min_coins[r-1][c] if r >= 1 else float('inf')
                with_coin = 1 + min_coins[r][c-coins[r]] if c >= coins[r] else float('inf')
                min_coins[r][c] = min(without_coin, with_coin)

        return min_coins[len(coins)-1][amount] if min_coins[len(coins)-1][amount] < float('inf') else -1

# BFS
    def coinChange(self, coins: List[int], amount: int) -> int:
        if coins is None or amount is None:
            return -1
        
        if amount == 0:
            return 0
        
        queue = deque([0])        
        seen = set()
        level = -1 
        while queue:
            level += 1
            for _ in range(len(queue)):
                node = queue.popleft()
                
                if node == amount:
                    return level
                
                for i in coins:
                    cur_sum = node + i 
                    
                    if cur_sum <= amount  and cur_sum not in seen:
                        queue.append(cur_sum)
                        seen.add(cur_sum)
              
        return -1  
