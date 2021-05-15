class Solution:
    def sortColors(self, nums: List[int]) -> None:
        RED, WHITE, BLUE = range(3)
        r, w, b = 0, 0, len(nums)-1
        while w <= b:
            if nums[w] == RED:
                nums[w], nums[r] = nums[r], nums[w]
                r += 1; w += 1
            elif nums[w] == BLUE:
                nums[w], nums[b] = nums[b], nums[w]
                b -= 1
            else:
                w += 1
