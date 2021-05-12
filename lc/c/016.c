bool canJump(int* nums, int numsSize){
    int farthest = 0, i = 0, j = numsSize-1;
    while (i <= farthest && farthest < j) {
        farthest = i+nums[i] > farthest ? i+nums[i] : farthest;
        i++;
    }
    return farthest >= j;
}
