/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - Shameer
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - None
*******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int get_random(int low, int high)
{
	srand(time(0));
	return (low + rand() % (high - low));
}

int main(int argc, char* argv[])
{
	int do_again;
	int is_input_wrong;
	int count = 0;
	int dice1;
	int dice2;
	char roll_again;
	
	printf("Dice Roller:\n");
	printf("------------\n");
	
	do {
		
		dice1 = get_random(1, 7);
		sleep(1);
		dice2 = get_random(1, 7);
		
		printf("\nRolling Dice 1: %d\n",dice1);
		printf("Rolling Dice 2: %d\n",dice2);
		
		/*
		//This is to check if input is good.
		//But it is not working that well.
		do {
			printf("Roll again?(y/n) ");
			scanf("%c",&roll_again);
			
			char temp;
			scanf("%c",&temp);
			
			printf("Roll again value is %c\n",roll_again);
			printf("Temp value is %c\n", temp);
			
			if ((roll_again == 'y') || (roll_again == 'Y'))
			{
				is_input_wrong = 0;
				do_again = 1;
			}
			else if ((roll_again == 'n') || (roll_again == 'N'))
			{
				is_input_wrong = 0;
				do_again = 0;
			}
			else
			{
				is_input_wrong = 1;
				printf("INPUT ERROR!\n");
			}
			
		} while(is_input_wrong);
		*/
		
		printf("Roll again? ");
		scanf("%c", &roll_again);
		
		//This doesn't check the input
		if ((roll_again == 'y') || (roll_again == 'Y'))
		{
			do_again = 1;
		}
		else
		{
			do_again = 0;
		}
		
		count++;
		
	} while(do_again);
	
	printf("\nYou rolled the dice %d times, goodbye!\n",count);
	
	return 0;
}