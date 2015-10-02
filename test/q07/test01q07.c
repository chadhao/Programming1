/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  IMPORTANT: REMEMBER TO sync BEFORE YOU LEAVE THE EXAM ROOM
*
*******************************************************************************/

#include <stdio.h>

//This function sends the error message when input is invalid.
void err_msg();

//This function handles the input number.
float number_input();

//This function handles the input unit. It take in i to identify "from" or "to".
char unit_input(int i);

//This function calculates the conversion.
float conversion(float number, char unit_from, char unit_to);

int main (int argc, char* argv[])
{
	float input_number;
	char unit_from;
	char unit_to;
	
	printf("Hello!\n");
	
	
	input_number = number_input();
	unit_from = unit_input(0);
	
	return 0;
}

void err_msg()
{
	printf("I don\'t recognise that unit. I can handle:\n");
	printf("\" - inches\n");
	printf("\' - feet\n");
	printf("c - centimeters\n");
	printf("m - meters\n");
}

float number_input()
{
	int number;
	int validation = 0;
	
	while (!validation)
	{
		printf("Please enter the number of units that you want to convert.\n");
		printf("> ");
		validation = scanf("%f", &number);	
		while(getchar()!='\n'){}
		if (validation == 0)
		{
			printf("Please enter a NUMBER.\n");
		}
	}
	
	return number;
}

char unit_input(int i)
{
	char unit;
	int validation = 0;
	
	while (!validation)
	{
		if (i == 0)
		{
			printf("What is the input unit?\n");
			printf("> ");
			scanf("%c", &unit);
			getchar();

			if (unit != '\"' || unit != '\'' || unit != 'c' || unit != 'm')
			{
				err_msg();
			}
			else
			{
				validation = 1;
			}
		}
		else
		{
			printf("What is the output unit?\n");
			printf("> ");
			scanf("%c", &unit);

			getchar();
			if (unit != '\"' || unit != '\'' || unit != 'c' || unit != 'm')
			{
				err_msg();
			}
			else
			{
				validation = 1;
			}
		}
	}
	
	return unit;
}

