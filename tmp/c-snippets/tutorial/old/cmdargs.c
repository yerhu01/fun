#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int i, j, k;
	i = 5;
	j = 7;
	k = i + j;
	printf("%d\n", k);
   if(argc == 2) {
      printf("The argument supplied is %s\n", argv[1]);
   }
   else if(argc > 2) {
      printf("Too many arguments supplied.\n");
   }
   else {
      printf("One argument expected.\n");
   }
   return 0;
}
