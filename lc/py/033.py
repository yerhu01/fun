# Hash Table O(n)
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ret = 0
        nums_set = set(nums)

        for num in nums_set:
            if num-1 not in nums_set:
                length = 0
                curr = num
                while curr in nums_set:
                    length += 1
                    curr += 1
                ret = max(ret, length)
        return ret

# Sorting O(nlogn)
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ret = 0
        length = 0
        nums.sort()
        for i in range(len(nums)):
            if i == 0 or nums[i] == nums[i-1]+1:
                length += 1
                ret = max(ret, length)
            elif  nums[i] > nums[i-1]+1:
                length = 1
        return ret
