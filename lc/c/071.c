/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int next_even = 0, next_odd = numsSize-1;
    while (next_even < next_odd) {
        if (nums[next_even] % 2 == 0)
            next_even++;
        else {
            int tmp = nums[next_even];
            nums[next_even] = nums[next_odd];
            nums[next_odd] = tmp;
            next_odd--;
        }
    }
    *returnSize = numsSize;
    return nums;
}
