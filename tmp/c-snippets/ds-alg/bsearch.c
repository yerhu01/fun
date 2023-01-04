#include <stdio.h>
#include <stdlib.h>

static int bisect_left(int *a, int size, int t)
{   
    int l = 0, m = 0, r = size-1, ret = -1;
    while (l <= r) {
        m = l + (r-l)/2; 
        if (a[m] > t) {
            r = m - 1;
        } else if (a[m] < t) {
            l = m + 1;
        } else { 
            ret = m;
            r = m - 1;
        }
    }
    return ret;
}

static int bisect_right(int *a, int size, int t)
{
    int l = 0, m = 0, r = size-1, ret = -1;
    while (l <= r) {
        m = l + (r-l)/2; 
        if (a[m] > t) {
            r = m - 1;
        } else if (a[m] < t) {
            l = m + 1;
        } else { 
            ret = m;
            l = m + 1;
        }
    }
    return ret;

}

static int binary_search(int *a, int size, int t)
{   
    int l = 0, m = 0, r = size-1;
    while (l <= r) {
        m = l + (r-l)/2; 
        if (a[m] > t) {
            r = m - 1;
        } else if (a[m] < t) {
            l = m + 1;
        } else { 
            return m;
        }
    }
    return -1;
}

int main() 
{
    return 0;
}
