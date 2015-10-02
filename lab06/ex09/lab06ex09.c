/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab06ex09.c
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

void reminder(char a, char b)
{
	if ((a == 'y' || a == 'Y') && (b == 'y' || b == 'Y'))
	{
		printf("\nReminder-Bot-2K15 says: \"WEAR-SUNBLOCK!\"\n\n");
	}
	else if ((a == 'y' || a == 'Y') && (b == 'n' || b == 'N'))
	{
		printf("\nReminder-Bot-2K15 says: \"GO-TO-THE-BEACH!\"\n\n");
	}
	else if ((a == 'n' || a == 'N') && (b == 'y' || b == 'Y'))
	{
		printf("\nReminder-Bot-2K15 says: \"TAKE-AN-UMBRELLA!\"\n\n");
	}
	else if ((a == 'n' || a == 'N') && (b == 'n' || b == 'N'))
	{
		printf("\nReminder-Bot-2K15 says: \"STAY-HOME-AND-PLAY-BOARD-GAMES!\"\n\n");
	}
	else
	{
		printf("Input error! Please input \'y\' or \'n\'.\n");
	}
}

int main(int argc, char* argv[])
{
	char sunny[256];
	char weekdays[256];
	
	printf("Welcome to Reminder-Bot-2K15!\n\n");
	printf("Is it sunny outside (y/n)? ");
	scanf("%[^\n]%*c", &sunny);
	printf("Is it a weekday (y/n)? ");
	scanf("%[^\n]%*c", &weekdays);
	
	if (sunny[1] != '\0' || weekdays[1] != '\0')
	{
		printf("Input error! Please input \'y\' or \'n\'.\n");
	}
	else
	{
		reminder(sunny[0], weekdays[0]);
	}
	
	printf("Thank you for using Reminder-Bot-2K15!\n");
	
	return 0;
}