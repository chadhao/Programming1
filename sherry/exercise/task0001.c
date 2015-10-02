//Basic command line input output.
//Generate random number
//for loop
//conditions

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
	int length;
	
	printf("How long is the password? ");
	scanf("%d", &length);
	
	for (int i = 0; i < length; i++)
	{
		int cat = get_random(0, 2);
		if (cat == 0)
		{
			printf("%c", get_random(48, 57));
		}
		else if (cat == 1)
		{
			printf("%c", get_random(97, 122));
		}
		else
		{
			printf("%c", get_random(65, 90));
		}
	}
	printf("\n");
	
	return 0;
}