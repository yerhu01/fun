#include <stdio.h>

struct element {
    char name[15];
    char symbol[3];
};

// array decay to pointer as function parameter => sizeof() gives ptr size

int main()
{
    // ARRAYS => no need to free array
    // PTRs => need to allocate and free

    // sizeof() prints # of chars if char array
    // otherwise need len = sizeof(a) / sizeof(a[0])

    //DECLARE
    int num1[3];
    
    //DECLARE AND INIT
    int num2[5] = {0}; // [0,0,0,0,0]
    int num3[5] = {1,2,3}; // [1,2,3,0,0]
    struct element e[] = { [0] = {"Neon", "Ne"}, [1] = {"Helium", "He"} };
    printf("%s", e[1].symbol);

    return 0;
}
