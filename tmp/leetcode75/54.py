class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ret = [1]*len(nums)
        left_product = 1
        for i in range(1, len(nums)):
            left_product *= nums[i-1]
            ret[i] = left_product

        right_product = 1
        for i in range(1, len(nums)):
            right_product *= nums[~i+1]
            ret[~i] *= right_product

        return ret
