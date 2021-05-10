class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, num in enumerate(nums):
            c = target - num
            if c in d:
                return [i, d[c]]
            d[num] = i
