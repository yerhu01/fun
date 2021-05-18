// Single DP
int rob(int* nums, int numsSize){
    int prev = 0, adj = 0;
    for (int i = 0; i < numsSize; ++i) {
        int max_val = nums[i]+prev > adj ? nums[i]+prev : adj;
        prev = adj;
        adj = max_val;
    }
    return adj;
}
