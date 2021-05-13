int maxSubArray(int* nums, int numsSize){
    int ret = INT_MIN, running_sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        running_sum = nums[i] > running_sum+nums[i] ? nums[i] : running_sum+nums[i];
        ret = running_sum > ret ? running_sum : ret;
    }
    return ret;
}
