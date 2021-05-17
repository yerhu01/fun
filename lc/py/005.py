class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret = []
        nums.sort()
        for i in range(len(nums)-2):
            if i == 0 or nums[i] != nums[i-1]: # no duplicates
                c = 0 - nums[i]
                j, k = i+1, len(nums)-1
                while j < k:
                    if nums[j] + nums[k] < c:
                        j += 1
                    elif nums[j] + nums[k] > c:
                        k -= 1
                    else:
                        ret.append([nums[i], nums[j], nums[k]])
                        while j < k and nums[j] == nums[j+1]: # no duplicates
                            j += 1
                        while j < k and nums[k] == nums[k-1]: # no duplicates
                            k -= 1
                        j += 1
                        k -= 1
        return ret
