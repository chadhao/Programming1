/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw06q01.c
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
********************************************************************************/

#include <stdio.h>

void message_printer(int times)
{
	printf("--Called: \"message_printer\" function...\n");
	
	for (int i = 0; i < times; i++)
	{
		printf("--Message Number %d\n", i+1);
	}
	
	if (times == 1)
	{
		printf("--Done! %d message printed.\n", times);
	}
	else
	{
		printf("--Done! %d messages printed.\n", times);
	}
}

int main(int argc, char* argv[])
{
	int i = 1;
	int t = 0;
	
	printf("Welcome to Question 6! (Choose 0 to quit!)\n");
	
	while (i)
	{
		printf("How many times would you like to repeat the message? ");
		scanf("%d", &t);
		if (t == 0)
		{
			printf("Programming finishing!!! Goodbye!\n");
			i = 0;
		}
		else if (t < 0)
		{
			printf("The number should be greater than or equal to 0!\n");
		}
		else
		{
			message_printer(t);
		}
	}
	
	return 0;
}