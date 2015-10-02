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
#include <time.h>

int random_dice()
{
	srand(clock());
	return (rand() % 6) + 1;
}

int roll_dice(int *address1, int *address2)
{
	printf("roll_dice: Starting roll_dice function!\n");
	printf("roll_dice: variable address1 holds the value: %d\n", *address1);
	printf("roll_dice: variable address2 holds the value: %d\n", *address2);
	printf("roll_dice: ROLLING TWO DICE!\n");
	
	*address1 = random_dice();
	*address2 = random_dice();
	
	printf("roll_dice: Assigning first dice to caller\'s memory...\n");
	printf("roll_dice: Assigning second dice to caller\'s memory...\n");
	printf("roll_dice: Returning sum of two dice...\n");
	
	return *address1 + *address2;
}

int main(int argc, char *argv[])
{
	int dice1 = 0;
	int dice2 = 0;
	int total_roll = 0;
	
	printf("main: Lab 08: Exercise 2:\n");
	printf("main: Starting main function:\n");
	printf("main: variable dice1 holds the value: %d\n", dice1);
	printf("main: variable dice1 stored at: %p\n", &dice1);
	printf("main: variable dice2 holds the value: %d\n", dice2);
	printf("main: variable dice2 stored at: %p\n", &dice2);
	printf("main: calling: roll_dice(%p, %p);\n", &dice1, &dice2);
	
	total_roll = roll_dice(&dice1, &dice2);
	
	printf("main: variable dice1 holds the value: %d\n", dice1);
	printf("main: variable dice1 stored at: %p\n", &dice1);
	printf("main: variable dice2 holds the value: %d\n", dice2);
	printf("main: variable dice2 stored at: %p\n", &dice2);
	printf("main: variable total_roll holds the value: %d\n", total_roll);
	printf("main: Returning zero to the operating system...\n");
	
	return 0;
}
