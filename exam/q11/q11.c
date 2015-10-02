
#include <stdio.h>
#include <stdlib.h>

#define TO_PRINT 10


int get_triangular_number(int n)
{
	//dont have conditions to end recursive algorithm.
	if (n > 0)
	{
		return n + get_triangular_number(n - 1);
	}
}

int* get_triangular_numbers(int how_many)
{
	//memory allocation error
	int* numbers = (int*)malloc(sizeof(int)*how_many);
	
	for(int n = 0; n < how_many; n++)
	{
		numbers[n] = get_triangular_number(n + 1);
	}
	return numbers;
}

void print_ints(int* numbers, int how_many)
{
	for(int n = 0; n < how_many; n++)
	{
		printf("%d\n", numbers[n]);
	}
}

int main(int argc, char* argv[])
{
	int* numbers = get_triangular_numbers(TO_PRINT);
	//sizeof(numbers) doesnt equals to how many to print.
	print_ints(numbers, TO_PRINT);
	free(numbers);
	return 0;
}