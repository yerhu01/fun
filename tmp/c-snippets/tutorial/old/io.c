#include <stdio.h>

int main()
{
	int a;
	float b;
	printf("Enter an integer and a float: ");
	scanf("%d %f", &a, &b);  
	printf("You entered %d and %.1f\n", a, b);
	return 0;
}
