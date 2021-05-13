class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit, min_so_far = 0, float('inf')
        for p in prices:
            day_profit = p - min_so_far
            max_profit = max(max_profit, day_profit)
            min_so_far = min(min_so_far, p)
        return max_profit
