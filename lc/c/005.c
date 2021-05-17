/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

static int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int max_sz = 64;
    int **ret = malloc(max_sz * sizeof *ret);
    int sz = 0;

    qsort(nums, numsSize, sizeof *nums, compare);

    for (int i = 0; i < numsSize-2; ++i) {
        if (i == 0 || nums[i] != nums[i-1]) {
            int c = 0 - nums[i];
            int j = i+1, k = numsSize-1;
            while (j < k) {
                if (nums[j] + nums[k] < c)
                    j++;
                else if (nums[j] + nums[k] > c)
                    k--;
                else {
                    if (sz == max_sz) {
                        max_sz *= 2;
                        ret = realloc(ret, max_sz * sizeof *ret);
                    }
                    ret[sz] = malloc(3 * sizeof **ret);
                    ret[sz][0] = nums[i];
                    ret[sz][1] = nums[j];
                    ret[sz++][2] = nums[k];
                    while (j < k && nums[j] == nums[j+1])
                        j++;
                    while (j < k && nums[k] == nums[k-1])
                        k--;
                    j++;
                    k--;
                }
            }
        }
    }

    *returnSize = sz;
    *returnColumnSizes = malloc(sz * sizeof **returnColumnSizes);
    for (int i = 0; i < sz; ++i)
        (*returnColumnSizes)[i] = 3;
    return ret;
}
