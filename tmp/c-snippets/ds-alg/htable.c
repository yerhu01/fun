#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define EMPTY 0x80808080

unsigned long djb2(unsigned char *str) {
    unsigned long hash = 5381;
    int c;
    while (c = *str++)
        hash = hash*33 + c;

    return hash;
}

int lookup (int *htable, int mask, int val) {
    unsigned hash = val; /* unsigned long hash = djb2(str); */
    int h = hash & mask;
    unsigned perturb = hash; /* unsigned long perturb = hash; */

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

int main() {
    int mask = hmask(100); // ex. 0xFFFF
    int htable[mask+1]; //power of 2 table size 0x10000
    memset(htable, 0x80, sizeof htable); //-inf

    int h = lookup(htable, mask, 3);
    if (htable[h] == 3)
        printf("3 is in table");
    else
        htable[h] = 3;

    return 0;
}
