class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ret = float('-inf')
        running_sum = 0
        for num in nums:
            running_sum = max(num, running_sum+num)
            ret = max(ret, running_sum)
        return ret
