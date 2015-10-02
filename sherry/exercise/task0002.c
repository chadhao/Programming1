//****************************************************
//  File Name: task0002.c
//  Date Released: 12-05-2015
//****************************************************
//  Task Description:
//  Write a guessing game(seems that we did it before in James' homework)
//  Generate a random number between 0 and 9.
//  Player can guess ONE time.
//  If the player is right, print out a congratulation message.
//  If the player is wrong, print out a sorry message and the right number.
//****************************************************
//  Hint:
//  Random number generator algorithm is exactly the same as used in the last task.
//  User need to input a number, you should store it in a variable.
//  You should use if statment to judge different conditions. 
//  You need stdio.h for standard input output, stdlib.h and time.h for random function in this task.
//****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random(int low, int high)
{
	srand(clock());
	return low + (rand() % (high - low + 1));
}

int main(int argc, char* argv[])
{
	int rand_number = get_random(0, 9);
	int user_number;
	
	printf("Please enter a number between 0 and 9: ");
	scanf("%d", &user_number);
	
	if (user_number == rand_number)
	{
		printf("Great! You are right!\n");
	}
	else
	{
		printf("Sorry, the correct number is %d.\n", rand_number);
	}
	
	return 0;
}
