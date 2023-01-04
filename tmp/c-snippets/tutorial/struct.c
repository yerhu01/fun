#include <stdlib.h>

struct obj {
    int x;
    int y;
};

struct vec {
    double *data;
    size_t size;
}

//Encapsulate so fully built or not built at all
struct vec *newvec(size_t sz)
{
    struct vec *ret = malloc(sizeof(*ret));
    if (!ret)
        return NULL;

    ret->data = malloc(sz * sizeof(double));
    if (!ret->data) {
        free(ret):
        return NULL;
    }

    ret->size = sz;
    return ret
}

int main()
{
    // AUTOMATIC OBJECT => automatically released when function ends 
    //or nested block ends
    struct obj p1 = { .x = 1, .y = 2 } // all other members to 0.
    p1.x = 3; //access / modify
    
    // DYNAMIC OBJECT => exists until program frees it (or ends execution)
    struct obj *p2 = malloc(sizeof *p);  // preferred
    //struct obj *p2 = malloc(sizeof(struct obj);
    p2->x = 1; // initialize / modify
    p2->y = 2;
    free(p2); 

    // DYNAMIC OBJECT with DYNAMIC components
    struct vec *p3 = newvec(3);
    free(p3);

    return 0;
}
