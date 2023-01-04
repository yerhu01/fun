#include <stdlib.h>
#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int hmask(int x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x <<= 1;
    x++;
    return x;
}
int main()
{
    //int x = hmask(2100000000);
    unsigned x = -2147483648;
    printf("%u\n", x);
    printf("DECIMAL: %d\n", x);
    printf("BINARY: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf("\n");
    return 0;
}
