# Sum without formula
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        expected_sum, actual_sum = 0, 0
        for i in range(1, len(nums)+1):
            expected_sum += i
            actual_sum += nums[i-1]
        return expected_sum - actual_sum

# bit manipulation
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        missing = len(nums)
        for i, num in enumerate(nums):
            missing ^= i ^ num
        return missing

# sum 0 to i = n(n+1)/2
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        expected_sum = len(nums)*(len(nums)+1)//2
        actual_sum = sum(nums)
        return expected_sum - actual_sum
