// Hash Table
#define EMPTY 0x80808080

int lookup (int *htable, int mask, int val) {
    unsigned hash = val;
    int h = hash & mask;
    unsigned perturb = hash;

    for (;;) {
        if (htable[h] == EMPTY || htable[h] == val)
            return h;

        // Handle collisions
        perturb >>= 5;
        h = (5*h + 1 + perturb) & mask;
    }
}

int hmask(int x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x;
}

int longestConsecutive(int* nums, int numsSize){
    int ret = 0;
    int mask = hmask(numsSize);
    int set[mask+1];
    memset(set, 0x80, sizeof set);
    for (int i = 0; i < numsSize; ++i)
        set[lookup(set, mask, nums[i])] = nums[i];

    for (int i = 0; i < mask+1; ++i) {
        if (set[i] != EMPTY && set[lookup(set, mask, set[i]-1)] == EMPTY) {
            int length = 0, curr = set[i];
            while (set[lookup(set, mask, curr)] != EMPTY) {
                length += 1;
                curr += 1;
            }
            ret = length > ret ? length : ret;
        }
    }
    return ret;
}

// Sorting
static int compare(void *a, void *b) {
    return *(int*)a - *(int*)b;
}

int longestConsecutive(int* nums, int numsSize){
    int ret = 0, length = 0;
    qsort(nums, numsSize, sizeof *nums, compare);

    for (int i = 0; i < numsSize; ++i) {
        if (i == 0 || nums[i] == nums[i-1]+1) {
            length += 1;
            ret = length > ret ? length : ret;
        } else if (nums[i] > nums[i-1]+1)
            length = 1;
    }
    return ret;
}
