/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
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
*******************************************************************************/
#include <stdio.h>

int adder(int a, int b)
{
	return (a + b);
}

int multiplier(int a, int b)
{
	return (a * b);
}

int main(int argc, char* argv[])
{
	int first_number = 4;
	int second_number = 7;
	
	printf("First number: %d\n",first_number);
	printf("Second number: %d\n",second_number);
	
	int adding_result = adder(first_number, second_number);
	
	printf("Adding result: %d\n",adding_result);
	
	int multiplying_result = multiplier(first_number, second_number);
	
	printf("Multiplying result: %d\n",multiplying_result);
	
	return 0;
}