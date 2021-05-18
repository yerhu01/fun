class Solution:
    def rob(self, nums: List[int]) -> int:
        def rob1(start, stop):
            prev = 0
            adj = 0
            for i in range(start, stop):
                max_val = max(adj, nums[i]+prev)
                prev = adj
                adj = max_val
            return adj

        if len(nums) == 1:
            return nums[0]

        return max(rob1(0, len(nums)-1), rob1(1, len(nums)))
