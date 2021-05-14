class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ret = float('-inf')
        curr_min, curr_max = 1, 1
        for num in nums:
            tmp = curr_max
            curr_max = max(curr_max*num, curr_min*num, num)
            curr_min = min(tmp*num, curr_min*num, num)
            ret = max(ret, curr_max)
        return ret
