void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortColors(int* nums, int numsSize){
    enum {RED, WHITE, BLUE};
    int r = 0, w = 0, b = numsSize-1;
    while (w <= b) {
        if (nums[w] == RED)
            swap(&nums[w++], &nums[r++]);
        else if (nums[w] == BLUE)
            swap(&nums[w], &nums[b--]);
        else
            w++;
    }
}
