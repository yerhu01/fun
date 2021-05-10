#define EMPTY 0x80808080

int lookup (int *htable, int mask, int *nums, int val) {
    unsigned hash = val;
    int h = hash & mask;
    unsigned perturb = hash;

    for (;;) {
        if (htable[h] == EMPTY || nums[htable[h]] == val)
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int mask = hmask(numsSize); // ex. 0xFFFF
    int htable[mask+1]; // power of 2 table size 0x10000
    memset(htable, 0x80, sizeof htable); // -inf
    *returnSize = 2;

    for (int i = 0; i < numsSize; ++i) {
        int c = target - nums[i];
        int h = lookup(htable, mask, nums, c);
        if (htable[h] != EMPTY) {
            int *ret = malloc(*returnSize * sizeof(int));
            ret[0] = i;
            ret[1] = htable[h];
            return ret;
        }
        htable[lookup(htable, mask, nums, nums[i])] = i;
    }
    return NULL;
}


/* UT HASHTABLE */
struct hash {
    int key, index;
    UT_hash_handle hh;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    struct hash *htable = NULL, *h, *tmp;
    *returnSize = 2;
    int *ret;
    int i, c;

    for (i = 0; i < numsSize; ++i) {
        c = target - nums[i];
        HASH_FIND_INT(htable, &c, h);
        if (h) {
            ret = malloc(sizeof(int) * (*returnSize));
            ret[0] = i;
            ret[1] = h->index;
            HASH_ITER(hh, htable, h, tmp) { free(h); }
            return ret;
        }
        h = malloc(sizeof(struct hash));
        h->key = nums[i];
        h->index = i;
        HASH_ADD_INT(htable, key, h);
    }

    HASH_ITER(hh, htable, h, tmp) { free(h); }
    return NULL;
}
