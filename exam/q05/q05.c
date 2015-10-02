
#include <stdio.h>


int main(int argc, char* argv[])
{
	int a = 17;
	int* b = &a;
	
	printf("The address of a is %u\n", &a);
	printf("The value of a is %d\n", a);
	printf("The address of b is %u\n", &b);
	printf("The value of b is %u\n", b);
	printf("The value of the variable that b points to is %d\n", *b);

	return 0;
}