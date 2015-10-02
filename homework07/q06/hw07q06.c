/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw07q06.c
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
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 10
#define TABLE_SIZE 10
#define LINE_LENGTH 1000


int* get_times_table(int n, int table_size)
{
		// I don't want to return static memory because it might get
		// overwritten, and I can't return stack memory, better make it dynamic
	int* my_table = (int *)malloc(table_size * sizeof(double));
	for(int i = 1; i <= table_size; i++)
	{
		my_table[i - 1] = n * i;
	}
	return my_table;
}

/*
Precompute a block with given dimensions, starting from smallest.
*/
int** get_block_of_times_tables(int smallest, int block_size, int table_size)
{
		// Hmm, the block is an array of pointers to arrays, each of which
		// holds a times table (in an array), so it is block_size long...
	int** result = (int**)malloc(block_size * sizeof(int*));
	for(int n = 0; n < block_size; n++)
	{
			// This is giving me an array, so I need to copy it into dynamically
			// allocated memory, so I can return it
		int* table = get_times_table(smallest + n, table_size);
			// I need table_size worth of ints...
		int* dynamic_table = (int*)malloc(table_size * sizeof(int));
			// Now I know a great function for this! memcpy!
		memcpy(dynamic_table, table, table_size * sizeof(int));
		free(table);
		result[n] = dynamic_table;
	}
	return result;
}


void print_times_table(int times_table[], int table_size)
{
		// Need to build a string
	char* output = (char *)malloc(sizeof(int) * LINE_LENGTH);
	char* p = output;	// Pointer to end of string
	for(int n = 0; n < table_size; n++)
	{
		sprintf(p, "%d ", times_table[n]);
		p = output + strlen(output);
	}
	sprintf(p, "\n");
		// Now print a line!
	printf("%s", output);
	free(output);
	free(times_table);
}

void print_block_of_times_tables(
	int** block_of_times_tables, int block_size, int table_size)
{
	for(int n = 0; n < block_size; n++)
	{
		print_times_table(block_of_times_tables[n], table_size);
	}
}

/* 

This program prints times tables for ever.  Each times table has TABLE_SIZE
elements and the tables are printed in blocks of BLOCK_SIZE, with blank lines 
between each block.  E.g. if BLOCK_SIZE and TABLE_SIZE were both 3 we would 
see:

0 0 0
1 2 3
2 4 6

3 6 9
4 8 12
5 10 15

6 12 18
...etc.

*/
int main(int argc, char* argv[])
{
		// Ok, so I'm going to need something to store a block
	int** block_of_times_tables;
		// Start with 1 times table
	int smallest_times_table = 1;
	for(;;)
	{
		block_of_times_tables = 
			get_block_of_times_tables(
				smallest_times_table, BLOCK_SIZE, TABLE_SIZE);
		print_block_of_times_tables(block_of_times_tables, BLOCK_SIZE, TABLE_SIZE);
		free(block_of_times_tables);
		printf("\n\n");
		smallest_times_table += BLOCK_SIZE;
	}
		// Let's not forget that the blocks are dynamically allocated!
		//free(block_of_times_tables);
		// Phew!
	return 0;
}