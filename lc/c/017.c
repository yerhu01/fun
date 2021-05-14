/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


/* HEAP */
static void swap(int **x, int **y) {
    int *tmp = *x;
    *x = *y;
    *y = tmp;
}

static bool compare(int *a, int *b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}

static void siftdown(int **heap, int n, int i) {
    int min = i;
    for (;;) {
        int left = i*2+1, right = i*2+2;
        if (left < n && compare(heap[left], heap[min]))
            min = left;
        if (right < n && compare(heap[right], heap[min]))
            min = right;

        if (min == i)
            return;

        swap(&heap[min], &heap[i]);
        i = min;
    }
}

static int* pop(int **heap, int *n) {
    int *min = heap[0];
    heap[0] = heap[*n-1];
    *n -= 1;
    siftdown(heap, *n, 0);
    return min;
}

static void heapify(int **heap, int n) {
    for (int i = n/2; i >= 0; --i)
        siftdown(heap, n, i);
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **ret = malloc(intervalsSize * sizeof(*ret));
    int sz = 0;

    heapify(intervals, intervalsSize);
    int *curr = pop(intervals, &intervalsSize);
    while (intervalsSize > 0) {
        int *nxt = pop(intervals, &intervalsSize);
        if (curr[1] < nxt[0]) {
            ret[sz++] = curr;
            curr = nxt;
        } else
            curr[1] = nxt[1] > curr[1] ? nxt[1] : curr[1];
    }
    ret[sz++] = curr;

    *returnSize = sz;
    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; ++i)
        (*returnColumnSizes)[i] = 2;
    return ret;
}

/* SORTING */
static int compare(const void *pa, const void *pb) {
    const int *a = *(int **)pa;
    const int *b = *(int **)pb;
    if (a[0] == b[0])
        return a[1] - b[1];
    else
        return a[0] - b[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **ret = malloc(intervalsSize * sizeof(*ret));
    int sz = 0;

    qsort(intervals, intervalsSize, sizeof(*intervals), compare);
    int *curr = intervals[0];
    for (int i = 1; i < intervalsSize; ++i) {
        if (curr[1] < intervals[i][0]) {
            ret[sz++] = curr;
            curr = intervals[i];
        } else
            curr[1] = intervals[i][1] > curr[1] ? intervals[i][1] : curr[1];
    }
    ret[sz++] = curr;

    *returnSize = sz;
    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; ++i)
        (*returnColumnSizes)[i] = 2;
    return ret;
}
