void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void push(int **heap, int *n, int *sz, int val) {
    if (*n == *sz) {
        *sz *= 2;
        *heap = realloc(*heap, *sz * sizeof **heap);
    }
    (*heap)[*n] = val;
    *n += 1;

    int i = *n-1, parent = (i-1)/2;
    while (i != 0 && (*heap)[parent] > (*heap)[i]) {
        swap(&(*heap)[parent], &(*heap)[i]);
        i = parent;
        parent = (i-1)/2;
    }
}

void cascade(int *heap, int n, int i) {
    int child, min = i;
    for (;;) {
        child = i << 1;
        if (++child < n && heap[child] < heap[min])
            min = child;
        if (++child < n && heap[child] < heap[min])
            min = child;

        if (min == i)
            return;

        swap(&heap[min], &heap[i]);
        i = min;
    }
}

int pop(int *heap, int *n) {
    int min = heap[0];
    heap[0] = heap[*n-1];
    *n -= 1;
    cascade(heap, *n, 0);
    return min;
}


typedef struct {
    int *less;
    int less_n;
    int less_sz;
    int *greater;
    int greater_n;
    int greater_sz;
} MedianFinder;

/** initialize your data structure here. */

MedianFinder* medianFinderCreate() {
    MedianFinder *mf = malloc(sizeof(*mf));
    mf->less_n = 0;
    mf->less_sz = 10;
    mf->less = malloc(mf->less_sz * sizeof(*mf->less));
    mf->greater_n = 0;
    mf->greater_sz = 10;
    mf->greater = malloc(mf->greater_sz * sizeof(*mf->greater));
    return mf;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    push(&obj->less, &obj->less_n, &obj->less_sz, -num);
    push(&obj->greater, &obj->greater_n, &obj->greater_sz, -pop(obj->less, &obj->less_n));
    if (obj->less_n < obj->greater_n)
        push(&obj->less, &obj->less_n, &obj->less_sz, -pop(obj->greater, &obj->greater_n));
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->less_n == obj->greater_n)
        return ((double) -obj->less[0] + (double) obj->greater[0])/2.0;
    else if (obj->less_n > obj->greater_n)
        return -obj->less[0];
    return 0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->less);
    free(obj->greater);
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);

 * double param_2 = medianFinderFindMedian(obj);

 * medianFinderFree(obj);
*/
