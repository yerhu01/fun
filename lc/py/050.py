# HASH TABLE
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return True if len(set(nums)) < len(nums) else False

    def containsDuplicate(self, nums: List[int]) -> bool:
        s = set()
        for n in nums:
            if n in s:
                return True
            s.add(n)
        return False

# SORTING
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        for i in range(len(nums)):
            if i+1 < len(nums) and nums[i] == nums[i+1]:
                return True
        return False
