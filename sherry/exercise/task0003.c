//****************************************************
//  File Name: task0003.c
//  Date Released: 13-05-2015
//****************************************************
//  Task Description:
//  Write a guessing game
//  Generate a random number between 0 and 9.
//  Player should guess until he/she gets the right number.
//  Print a welcome message before the game.
//  If the player is wrong, print a message and let the player try again.
//  If the player is right, print out a congratulation message as well as how many times the player tried.
//****************************************************
//  Hint:
//  Random number generator algorithm is exactly the same as used in the last task.
//  User need to input a number, you should store it in a variable.
//  You should use if statment to judge different conditions.
//  You should use a while loop.
//  You need stdio.h for standard input output, stdlib.h and time.h for random function in this task.
//****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random(int low, int high)
{
	srand(clock());
	return low + (rand() % (high - low +1));
}

int main(int argc, char* argv[])
{
    int random_number = get_random(0, 9);
	int counter = 0;
	int user_number = 10;
	while(user_number != random_number)
	{
		printf("Your guess: ");
		scanf("%d", &user_number);
		counter++;
		if (user_number == random_number)
		{
			printf("You are right! You tried %d times.\n", counter);
		}
		else
		{
			printf("Please try again!\n");
		}
	}
    return 0;
}