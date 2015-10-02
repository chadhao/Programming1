/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  Author:     Sherry Hong
*  Student Id: 14874433
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - None
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int* resize_dynamic_array(int* p, int old_size, int new_size)
{
	printf("resize_dynamic_array called: \n");
	int* new_arr = (int *)malloc(new_size * sizeof(int));
	for (int i = 0; i < old_size; i++)
	{
		new_arr[i] = p[i];
	}
	free(p);
	return new_arr;
}

int main(int argc, char* argv[])
{
	int* data = 0;
	printf("1) data starts at: %p \n", data);
	data = resize_dynamic_array(data, 0, 10);
	printf("2) data starts at: %p \n", data);
	for (int i = 0; i < 10; ++i)
	{
		data[i] = i * 2;
	}
	data = resize_dynamic_array(data, 10, 15);
	printf("3) data starts at: %p \n", data);
	for (int i = 5; i < 15; ++i)
	{
		data[i] = i * 3;
	}
	printf("4) data starts at: %p \n", data);
	for (int i = 0; i < 15; ++i)
	{
		printf("data[%d] is storing: %d \n", i, data[i]);
	}
	return (0);
}
