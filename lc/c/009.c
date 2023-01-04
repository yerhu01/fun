
static int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

static void dfs(int *combo, int comboSize, int total, int index){
    if (total == target) {
        
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int max_sz = 64;
    int **ret = malloc(max_sz * sizeof *ret);
    int sz = 0;

    qsort(candidates, candidatesSize, sizeof *candidates, compare);

}
