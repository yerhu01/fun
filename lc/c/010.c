// Optimized
int search(int* nums, int numsSize, int target){
    int l = 0, r = numsSize-1;
    while (l <= r) {
        int m = l + (r-l)/2;
        if (nums[m] == target)
            return m;
        else if (nums[l] <= nums[m]) {
            if (nums[l] <= target && target < nums[m])
                r = m-1;
            else
                l = m+1;
        } else {
            if (nums[m] < target && target <= nums[r])
                l = m+1;
            else
                r = m-1;
        }
    }
    return -1;
}

// Find min_idx
int search(int* nums, int numsSize, int target){
    int l = 0, r = numsSize-1;
    // Find min_idx
    while (l < r) {
        int m = l + (r-l)/2;
        if (nums[m] > nums[r])
            l = m+1;
        else
            r = m;
    }

    // l = r = min_idx
    if (nums[l] <= target && target <= nums[numsSize-1])
        r = numsSize-1;
    else
        l = 0;

    // Binary search
    while (l <= r) {
        int m = l + (r-l)/2;
        if (nums[m] < target)
            l = m+1;
        else if (nums[m] > target)
            r = m-1;
        else
            return m;
    }
    return -1;
}
