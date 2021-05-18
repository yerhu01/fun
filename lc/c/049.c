int rob1(int *nums, int start, int stop) {
    int prev = 0, adj = 0;
    for (int i = start; i < stop; ++i) {
        int max_val = prev+nums[i] > adj ? prev+nums[i] : adj;
        prev = adj;
        adj = max_val;
    }
    return adj;
}

int rob(int* nums, int numsSize){
    if (numsSize == 1)
        return nums[0];

    int max1 = rob1(nums, 0, numsSize-1);
    int max2 = rob1(nums, 1, numsSize);
    return max1 > max2 ? max1 : max2;
}
