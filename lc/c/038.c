#define max(a, b, c) ((a>b ? a : b) > c ? (a>b ? a : b) : c)
#define min(a, b, c) ((a<b ? a : b) < c ? (a<b ? a : b) : c)

int maxProduct(int* nums, int numsSize){
    int ret = INT_MIN;
    int curr_min = 1, curr_max = 1;
    for (int i = 0; i < numsSize; ++i) {
        int tmp = curr_max;
        curr_max = max(curr_max*nums[i], curr_min*nums[i], nums[i]);
        curr_min = min(tmp*nums[i], curr_min*nums[i], nums[i]);
        ret = curr_max > ret ? curr_max : ret;
    }
    return ret;
}
