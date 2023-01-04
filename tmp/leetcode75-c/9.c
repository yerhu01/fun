// Space Optimized
void swap(struct ListNode **x, struct ListNode **y) {
    struct ListNode *tmp = *x;
    *x = *y;
    *y = tmp;
}

void cascade(struct ListNode **heap, int n, int i) {
    int child, min = i;
    for (;;) {
        child = i << 1;
        if (++child < n && (!heap[min] || heap[child] && heap[child]->val < heap[min]->val))
            min = child;
        if (++child < n && (!heap[min] || heap[child] && heap[child]->val < heap[min]->val))
            min = child;

        if (min == i)
            return;

        swap(&heap[min], &heap[i]);
        i = min;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (lists == NULL || listsSize == 0) 
        return NULL;
    
    struct ListNode dummy = {};
    struct ListNode *tail = &dummy;
    struct ListNode **heap = lists;
    
    /* Heapify */
    for (int i = listsSize/2; i >= 0; --i) 
        cascade(heap, listsSize, i);
    
    while (heap[0]) {
        tail->next = heap[0];
        tail = tail->next;
        heap[0] = heap[0]->next;
        cascade(heap, listsSize, 0);
    }
    return dummy.next;
}

// Min heap
void swap(struct ListNode **x, struct ListNode **y) {
    struct ListNode *tmp = *x;
    *x = *y;
    *y = tmp;
}

void push(struct ListNode **heap, int *n, struct ListNode *node) {
    heap[*n] = node;
    *n += 1;

    int i = *n-1, parent = (i-1)/2;
    while (i != 0 && heap[parent]->val > heap[i]->val) {
        swap(&heap[parent], &heap[i]);
        i = parent;
        parent = (i-1)/2;
    }
}

void cascade(struct ListNode **heap, int n, int i) {
    int child, min = i;
    for (;;) {
        child = i << 1;
        if (++child < n && heap[child]->val < heap[min]->val)
            min = child;
        if (++child < n && heap[child]->val < heap[min]->val)
            min = child;

        if (min == i)
            return;

        swap(&heap[min], &heap[i]);
        i = min;
    }
}

struct ListNode* pop(struct ListNode **heap, int *n) {
    struct ListNode *min = heap[0];
    heap[0] = heap[*n-1];
    *n -= 1;
    cascade(heap, *n, 0);
    return min;
}

void heapify(struct ListNode **heap, int n) {
    for (int i = n/2; i >= 0; --i)
        cascade(heap, n, i);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (lists == NULL || listsSize == 0)
        return NULL;

    struct ListNode dummy = {};
    struct ListNode *tail = &dummy;

    //struct ListNode *heap[listsSize];
    struct ListNode **heap = lists;
    int n = 0;

    for (int i = 0; i < listsSize; ++i) {
        if (lists[i])
            heap[n++] = lists[i];
    }
    heapify(heap,n);

    while (n > 0) {
        struct ListNode *node = pop(heap, &n);
        tail->next = node;
        tail = tail->next;
        node = node->next;
        if (node)
            push(heap, &n, node);
    }
    return dummy.next;
}
//HELPER
void print(struct ListNode **a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            printf("%d ", a[i]->val);
        }
        else {
            printf("NIL ");
        }
    }
    printf("\n");
}

