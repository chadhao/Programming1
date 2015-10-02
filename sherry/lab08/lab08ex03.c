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

void zero_out_array(int* p_array, int num_elements)
{
	printf("zero_out_array called: \n");
	for (int i = 0; i < num_elements; i++)
	{
		*(p_array + i) = 0;
	}
}
void print_array(int* p_array, int num_elements)
{
	printf("print_array called: \n");
	for (int i = 0; i < num_elements; i++)
	{
		printf("%d\n", p_array[i]);
	}
}

int main(int argc, const char * argv[])
{
	int main_array[] = { 10, 20, 30, 40, 50 };
	print_array(main_array, 5);
	zero_out_array(main_array, 5);
	print_array(main_array, 5);
	return 0;
}
