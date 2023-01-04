#include <stdio.h>

void pointer_array(int *a, size_t n) // int *a or int a[]
{
	size_t i;
	for (i = 0; i < n; ++i) {
		a[i] = i + 100;
	}

	for (size_t i = 0; i < n; ++i) {
		printf("Element[%ld] = %d\n", i, a[i]);
	}
}

void array()
{
	int a[10]; // OR int a[] = {10, 20, 30};
	size_t n = sizeof(a)/sizeof(*a); // *a = a[0]

	for (size_t i = 0; i < n; ++i) {
		a[i] = i + 100;
	}

	for (size_t i = 0; i < n; ++i) {
		printf("Element[%ld] = %d\n", i, a[i]);
	}

}

int main()
{
	array();
	printf("\n");

	size_t n = 10;
	int a[n];	
	pointer_array(a, n); // a is address of array
	return 0;
}
