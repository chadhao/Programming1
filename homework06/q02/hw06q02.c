/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw06q02.c
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - None
********************************************************************************/

#include <stdio.h>

void print_hash()
{
	printf("#");
}

void print_newline()
{
	printf("\n");
}

void print_single_space()
{
	printf(" ");
}

void square()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			print_hash();
		}
		print_newline();
	}
}

void triangle()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			print_hash();
		}
		print_newline();
	}
}

void inverted_triangle()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 5; j > i; j--)
		{
			print_hash();
		}
		print_newline();
	}
}

void right_aligned_triangle()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j > i; j--)
		{
			print_single_space();
		}
		for (int k = 0; k < i+1; k++)
		{
			print_hash();
		}
		print_newline();
	}
}

void inverted_right_aligned_triangle()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			print_single_space();
		}
		for (int k = 5; k > i; k--)
		{
			print_hash();
		}
		print_newline();
	}
}

int main(int argc, char* argv[])
{
	printf("1) Square:\n");
	square();
	
	printf("\n2) Triangle:\n");
	triangle();

	printf("\n3) Inverted Triangle:\n");
	inverted_triangle();

	printf("\n4) Right-Aligned Triangle:\n");
	right_aligned_triangle();

	printf("\n5) Inverted Right-Aligned Triangle:\n");
	inverted_right_aligned_triangle();
	
	return 0;
}