# Single DP
class Solution:
    def rob(self, nums: List[int]) -> int:
        prev = 0
        adj = 0
        for num in nums:
            max_val = max(adj, prev + num)
            prev = adj
            adj = max_val
        return adj

# 1D DP
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, len(nums)):
                dp[i] = max(dp[i-1], dp[i-2]+nums[i])
        return dp[-1]
