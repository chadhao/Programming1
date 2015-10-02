/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw04q03.c
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - Sam
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - None
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int get_random(int low, int high)
{
	srand(time(0));
	return (low + rand() % (high - low));
}

void guess_the_number()
{
	int count = 0;
	int is_guess_wrong = 1;
	int is_input_wrong = 1;
	int random_number;
	int guess_number;
	int scanf_number;
	
	random_number = get_random(0, 101);
	printf("I\'m thinking of a number between 0 and 100, what is it?\n");
	
	while (is_guess_wrong)
	{
		while (is_input_wrong)
		{
			printf("Your guess: ");
			scanf_number = scanf("%d", &guess_number);
			while(getchar() != '\n'){}
			
			if (scanf_number == 0 || guess_number < 0 || guess_number > 100)
			{
				printf("Please input an integer between 0 and 100!\n");
			}
			else
			{
				is_input_wrong = 0;
			}
		}
		
		is_input_wrong = 1;
		count++;
		
		if (guess_number == random_number)
		{
			printf("You got it!\n");
			printf("It took you %d guesses.\n", count);
			is_guess_wrong = 0;
		}
		else if (guess_number > random_number)
		{
			printf("Lower\n");
		}
		else
		{
			printf("Higher\n");
		}
	}
}

int main(int argc, char* argv[])
{
	guess_the_number();
	return 0;
}