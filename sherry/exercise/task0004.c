//****************************************************
//  File Name: task0004.c
//  Date Released: 15-05-2015
//****************************************************
//  Task Description:
//  Write a guessing game
//  Generate a random number between 0 and 9.
//  Let the player guess three times at the beginning.
//  If one of the numbers is right, print a message to tell the player which is the right one.
//  If there is no right answer, print a sorry message and the right number. 
//****************************************************
//  Hint:
//  Random number generator algorithm is exactly the same as used in the last task.
//  User need to input three numbers at a time.
//  you should store the three numbers in an array.
//  You should use if statment to judge different conditions.
//  You should use a for loop for user to enter numbers.
//  You can use break to end a loop.
//  You need stdio.h for standard input output, stdlib.h and time.h for random function in this task.
//****************************************************
//  Here is an example:
/*
Welcome to guessing game!
Please enter three number between 0 and 9.
Number 1: 7
Number 2: 0
Number 3: 2
Bingo! Number 2 is the right answer!
*/
//****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random(int low, int high)
{
	srand(clock());
	return low + (rand()%(high-low+1));
}
int main(int argc, char* argv[])
{
	int random_number = get_random(0, 9);
	int guess[3];
	int t = 0;
	printf("Welcome to guessing game!\n");
	printf("Please enter three number between 0 and 9.\n");
	
	for (int i = 0; i < 3; i++)
	{
		printf("Number %d: ", i+1);
		scanf("%d", &guess[i]);
	}
	
	for (int i = 0; i < 3; i++)
	{
		if (guess[i] == random_number)
		{
			printf("Bingo! Number %d is the right answer!\n", i+1);
			t++;
			break;
		}
	}
	if (t == 0)
	{
		printf("Sorry, Sherry!\n");
	}
	return 0;
}