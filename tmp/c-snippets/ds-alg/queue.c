#include <stdio.h>
#include <stdlib.h>

/* Circular array queue
**
**
*/
int *resize_queue(int *q, int *mask, int *f, int *r) {
    int old_sz = *mask+1;
    *mask = (*mask << 1) + 1;
    if (*f < *r)
        return realloc(q, (*mask+1) * sizeof *q);
    else {
        int *tmp = malloc((*mask+1) * sizeof *tmp);
        int i = 0;
        for (int j = *f; j < old_sz; ++j, ++i)
            tmp[i] = q[j];
        for (int j = 0; j < *r; ++j, ++i)
            tmp[i] = q[j];
        *f = 0; *r = i;
        free(q);
        return tmp;
    }
}

void print(int *q, int mask, int f, int r) {
    if (f < r) {
        for (int i = f; i < r; ++i)
            printf("%d ", q[i]);
        printf("\n");
    } else if (f == r) {
        printf("Queue empty\n");
    } else {
        for (int i = f; i < mask+1; ++i)
            printf("%d ", q[i]);
        for (int i = 0; i < r; ++i)
            printf("%d ", q[i]);
        printf("\n");
    }
}

int main() {
    int mask = 0xF, f = 0, r = 0; // NOTE: f will have value, r will not
    int *q = malloc((mask+1) * sizeof *q);

    int count = 40;
    q[r++] = count--;
    print(q, mask, f, r);
    while (r-f & mask) { // r-f % array_size = len(q)   OR  f != r (since f == r means empty)
        int x = q[f++ & mask]; // popleft
        //int x = q[--r & mask]; // pop
        printf("Popped: %d\n", x);
        if (count > 0) {
            q[r++ & mask] = count--; //append
            q[r++ & mask] = count--; //append
            //q[--f & mask] = count--; //appendleft
            //q[--f & mask] = count--; //appendleft
        }
        f &= mask; r &= mask;

        print(q, mask, f, r);

        // Resize if necessary OR f == r+1 || (f == 0 && r == mask)
        if ((r-f & mask) >= mask) { // NOTE: not mask+1 since cant be fully full. otherwise r==f (empty) even though it is full
            printf("Resizing...\n");
            q = resize_queue(q, &mask, &f, &r);
        }
    }
    free(q);

    /* Non dynamic queue
    int q[100], f = 0, r = 0; //f == r means empty
    while (f < r)
    */
    return 0;
}
