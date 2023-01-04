#include <stdio.h>

int main() {
    // %d
    unsigned x = -1;
    printf("%u\n", x);

    //overflow
    int z = 2100000000;
    int y = z + z;
    printf("%d\n", y);
    unsigned a = 4200000000;
    unsigned b = a + a;
    printf("%u\n", b);
    return 0;
}
