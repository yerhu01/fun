/* HASH TABLE */
#define EMPTY 0x80808080

int lookup (int *htable, int mask, int val) {
    unsigned hash = val;
    int h = hash & mask;
    unsigned perturb = hash;

    for (;;) {
        if (htable[h] == val || htable[h] == EMPTY)
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

bool containsDuplicate(int* nums, int numsSize){
    int mask = hmask(numsSize); // ex. 0xFFFF
    int htable[mask+1]; // power of 2 table size 0x10000
    memset(htable, 0x80, sizeof htable); // -inf

    for (int i = 0; i < numsSize; ++i) {
        int h = lookup(htable, mask, nums[i]);
        if (htable[h] == nums[i])
            return true;
        else
            htable[h] = nums[i];
    }
    return false;
}

/* SORTING */
static int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize; ++i) {
        if (i+1 < numsSize && nums[i] == nums[i+1])
            return true;
    }
    return false;
}


// UT HASH TABLE
#include "uthash.h"
struct hash {
    int key;
    int index;
    UT_hash_handle hh;
};

bool containsDuplicate(int* nums, int numsSize){
    struct hash *htable = NULL, *h, *tmp;
    int i;
    for (i = 0; i < numsSize; ++i) {
        HASH_FIND_INT(htable, &nums[i], h);
        if (h) {
            HASH_ITER(hh, htable, h, tmp) { free(h); }
            return true;
        }
        h = malloc(sizeof(struct hash));
        h->key = nums[i];
        h->index = i;
        HASH_ADD_INT(htable, key, h);
    }
    HASH_ITER(hh, htable, h, tmp) { free(h); }
    return false;
}

// UT HASH COUNT
bool containsDuplicate(int* nums, int numsSize){
    struct hash *htable = NULL, *h, *tmp;
    int i, count;
    for (i = 0; i < numsSize; ++i) {
        HASH_FIND_INT(htable, &nums[i], h);
        if (!h) {
            h = malloc(sizeof(struct hash));
            h->key = nums[i];
            h->index = i;
            HASH_ADD_INT(htable, key, h);
        }
    }
    count = HASH_COUNT(htable);
    HASH_ITER(hh, htable, h, tmp) { free(h); }
    return (count < numsSize) ? true : false;
}
