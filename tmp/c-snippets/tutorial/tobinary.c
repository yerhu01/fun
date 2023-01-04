#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

int pow2(int x){ //find smallest power of 2 >= x
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x++; // 01000000 format, without this line: 00111111 => good for mask
    //x >>= 1; // find msb (greatest power of 2 <= x)
    return x;
}

int main() 
{
    //int x = ~(~0u << 4);
    int x = pow2(20);
    //int x = 
    printf("DECIMAL: %d\n", x);
    printf("BINARY: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf("\n");
    return 0;
}
