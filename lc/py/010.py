# Optimized
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        while l <= r:
            m = l + (r-l)//2
            if nums[m] == target:
                return m
            elif nums[l] <= nums[m]: # nums[l] to nums[m] sorted
                if nums[l] <= target < nums[m]:
                    r = m-1
                else:
                    l = m+1
            else: # nums[m] to nums[r] sorted
                if nums[m] < target <= nums[r]:
                    l = m+1
                else:
                    r = m-1
        return -1

# Find min_idx first
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        # Find min_idx
        while l < r:
            m = l + (r-l)//2
            if nums[m] > nums[r]:
                l = m+1
            else:
                r = m

        # l = r = min_idx
        if nums[l] <= target <= nums[-1]:
            r = len(nums)-1
        else:
            l = 0

        # Binary search
        while l <= r:
            m = l + (r-l)//2
            if nums[m] < target:
                l = m+1
            elif nums[m] > target:
                r = m-1
            else:
                return m
        return -1
