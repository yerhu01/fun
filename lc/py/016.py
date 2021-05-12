class Solution:
    def canJump(self, nums: List[int]) -> bool:
        farthest, i, j = 0, 0, len(nums)-1
        while i <= farthest and farthest < j:
            farthest = max(farthest, i+nums[i])
            i += 1
        return farthest >= j
