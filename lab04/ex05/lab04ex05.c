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
*   - scanf format string - Wikipedia <http://en.wikipedia.org/wiki/Scanf_format_string>
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
	int first_number;
	int second_number;
	
	printf("Welcome to the Raspberry Pi Adder and Multiplier!\n");
	printf("-------------------------------------------------\n\n");
	
	printf("Input a number: ");
	scanf("%d",&first_number);
	
	printf("Input another number: ");
	scanf("%d",&second_number);
	
	printf("\n--------------\n");
	printf("Calculating...\n");
	printf("--------------\n\n");
	
	int adding_result = adder(first_number, second_number);
	
	printf("%d plus %d is %d\n\n",first_number, second_number, adding_result);
	
	int multiplying_result = multiplier(first_number, second_number);
	
	printf("%d times %d is %d\n\n",first_number, second_number, multiplying_result);
	
	printf("-------\n");
	printf("Thanks!\n");
	
	return 0;
}