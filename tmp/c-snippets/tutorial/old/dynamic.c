#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *des;
	// Allocate
	des = malloc(5 * sizeof(char)); //OR calloc(5, sizeof(char))
	if (!des)
		goto err;

	strcpy(des, "Hello.");
	printf("%s\n", des);

	// Resize
	des = realloc(des, 30 * sizeof(char));
	if (!des)
		goto err;

	strcat(des, " How are you?");
	printf("%s\n", des);

	// Free
	free(des);
	return 0;

err:
	return 1;
}
