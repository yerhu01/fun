#include <stdio.h>
#include <stdlib.h>

static void pointer_access()
{
	// Pointer to array of pointers
	int **a = malloc(6 * sizeof(int*));
	size_t n = 6, m = 6;
	size_t i, j;
	int count = 0;

	// Initialize
	for (i = 0; i < n; ++i) { // Row
		*(a + i) = malloc(6 * sizeof(int));

		for (j = 0; j < m; ++j) { // Column
			*(*(a+i)+j) = count;
			++count;
		}
	}

	// Access
	for (i = 0; i < n; ++i) {
		printf("\n");
		for (j = 0; j < m; ++j) {
			printf("%d ", *(*(a+i)+j));
		}
	}
	printf("\n");
	free(a);
}

static void array_access()
{
	// Pointer to array of pointers
	int **a = malloc(6 * sizeof(int*));
	size_t n = 6, m = 6;
	size_t i, j;
	int count = 0;

	// Initialize
	for (i = 0; i < n; ++i) { // Row
		a[i] = malloc(6 * sizeof(int));

		for (j = 0; j < m; ++j) { // Column
			a[i][j] = count;
			++count;
		}
	}
	
	// Access
	for (i = 0; i < n; ++i) {
		printf("\n");
		for (j = 0; j < m; ++j) {
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
	free(a);

}

int main()
{
	pointer_access();
	array_access();
	return 0;
}
