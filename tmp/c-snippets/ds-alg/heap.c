#include <stdio.h>

/* MIN HEAP
** parent = (i-1)/2, left = 2*i+1, right = 2*i+2
** insert = O(logn), peek = O(1)
** pop = O(logn)
** heapify = O(n) */

# define MAX_SIZE 15

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void push(int *heap, int *n, int val) {
    //if (*n >= MAX_SIZE) { return; } // HEAP FULL
    heap[*n] = val;
    *n += 1;

    int i = *n-1, parent = (i-1)/2;
    while (i != 0 && heap[parent] > heap[i]) {
        swap(&heap[parent], &heap[i]);
        i = parent;
        parent = (i-1)/2;
    }
}

/* DYNAMIC HEAP
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
*/

void siftdown(int *heap, int n, int i) {
    int min = i;
    for (;;) {
        int left = i*2+1, right = i*2+2;
        if (left < n && heap[left] < heap[min])
            min = left;
        if (right < n && heap[right] < heap[min])
            min = right;

        if (min == i)
            return;

        swap(&heap[min], &heap[i]);
        i = min;
    }
}

int pop(int *heap, int *n) {
    //if (*n <= 0) { return -1; } // HEAP EMPTY
    int min = heap[0];
    heap[0] = heap[*n-1];
    *n -= 1;
    siftdown(heap, *n, 0);
    return min;
}

void heapify(int *heap, int n) {
    for (int i = n/2; i >= 0; --i)
        siftdown(heap, n, i);
}


void print(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main() {
    int n = 10;
    int a[MAX_SIZE] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    heapify(a, n);
    print(a, n);
    push(a, &n, 3);
    push(a, &n, 21);
    push(a, &n, 0);
    push(a, &n, 0);
    print(a,n);
    while (n) {
        printf("%d\n", pop(a, &n));
    }
    return 0;
}
