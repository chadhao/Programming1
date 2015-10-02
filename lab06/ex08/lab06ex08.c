/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab06ex08.c
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

#include "p1student.h"
#include "stdio.h"

int main(int argc, char* argv[])
{
	int first;
	int second;
	
	printf("Hello User!\n");
	printf("Please enter the first number: ");
	scanf("%d", &first);
	printf("Please enter the second number: ");
	scanf("%d", &second);
	printf("Calculating...\n");
	printf("%d plus %d is %d\n", first, second, first + second);
	printf("%d minus %d is %d\n", first, second, first - second);
	printf("%d times %d is %d\n", first, second, first * second);
	printf("%d divided by %d is %d\n", first, second, first / second);
	printf("%d modulus %d is %d\n", first, second, first % second);
	printf("Thank you! Goodbye!\n");

	return 0;
}