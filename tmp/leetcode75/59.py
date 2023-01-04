# DP with binary search

# DP Solution for Increasing
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        max_length = [1] * len(nums) 
        for i in range(1, len(nums)):
            max_length[i] = 1 + max([max_length[j] for j in range(i) if nums[i] > nums[j]], default=0)
        return max(max_length)
#also works initialize to 0
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        max_length = [0] * len(nums)
        for i in range(len(nums)):
            max_length[i] = 1 + max([max_length[j] for j in range(i) if nums[i] > nums[j]], default=0)
        return max(max_length)


# DP Solution from EPI16.12 NONDECREASING SUBSEQUENCE
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        max_length = [1] * len(nums)  
        for i in range(1, len(nums)):
            max_length[i] = max(1 + max(
                [max_length[j] for j in range(i)
                 if nums[i] >= nums[j]], default=0), max_length[i])
        return max(max_length)

# in different form
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        max_length = [1] * len(nums)  
        for i in range(1, len(nums)): 
            maxval = 0 # max of max_length up to i
            for j in range(i):
                if nums[i] > nums[j]:
                    maxval = max(maxval, max_length[j])
            max_length[i] = maxval+1
        return max(max_length)
