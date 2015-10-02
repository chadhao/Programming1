/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       main.c
*  Author:     Joy Hong
*  Student Id: 
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - http://en.wikipedia.org/wiki/Yahtzee
*   - https://www.daniweb.com/software-development/c/threads/410155/gcc-equivalent-for-getch
*   - http://stackoverflow.com/questions/3219393
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "yahtzee.h"

int getch()
{
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}

int main(int argc, char* argv[])
{
	struct dice a[5];
	struct board b = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int out = 0;
	
	while(1)
	{
		for (int i=0; i<5; i++)
		{
			a[i].is_hold = 0;
		}
		
		int i = 0;
		dice_random(a);
		while(1)
		{
			system("clear");
			printf("\n\n++++++++++++Yahtzee!++++++++++++\n\n\n");
			print_dice(a);
			printf("Time of rolls: %d\n", i+1);
			printf("\nControl Keys\n[r: roll dice] [t: stop roll]\n[q, w, e, a, s: hold or unhold each dice]\n\n");
			print_board(0, a, &b);
			if (i == 2)
			{
				break;
			}
			int input = getch();
			if (input == 116)
			{
				i = 0;
				break;
			}
			else if (input == 114)
			{
				dice_random(a);
			}
			else if (input == 113)
			{
				change_hold(0, a);
				continue;
			}
			else if (input == 119)
			{
				change_hold(1, a);
				continue;
			}
			else if (input == 101)
			{
				change_hold(2, a);
				continue;
			}
			else if (input == 97)
			{
				change_hold(3, a);
				continue;
			}
			else if (input == 115)
			{
				change_hold(4, a);
				continue;
			}
			else
			{
				continue;
			}
			i++;
		}
		
		while(1)
		{
			system("clear");
			printf("\n\n++++++++++++Yahtzee!++++++++++++\n\n\n");
			print_dice(a);
			printf("Finished rolling!\n\n");
			printf("Please assign your point to one category!\n");
			printf(COLOR_RED"Red number"COLOR_RESET);
			printf(" indicates that category is already assigned!\n");
			printf(COLOR_GREEN"Green number"COLOR_RESET);
			printf(" indicates the possible value of that category!\n\n");
			printf("Control Keys\n[x: exit] [1-6: assign point]\n\n");
		
			print_board(1, a, &b);
		
			int input = getch();
			if (input == 120)
			{
				out = 1;
				break;
			}
			else if (input == 49)
			{
				if (b.ones != -1)
				{
					continue;
				}
				b.ones = upper(1, a);
				check_upper(&b);
				break;
			}
			else if (input == 50)
			{
				if (b.twos != -1)
				{
					continue;
				}
				b.twos = upper(2, a);
				check_upper(&b);
				break;
			}
			else if (input == 51)
			{
				if (b.threes != -1)
				{
					continue;
				}
				b.threes = upper(3, a);
				check_upper(&b);
				break;
			}
			else if (input == 52)
			{
				if (b.fours != -1)
				{
					continue;
				}
				b.fours = upper(4, a);
				check_upper(&b);
				break;
			}
			else if (input == 53)
			{
				if (b.fives != -1)
				{
					continue;
				}
				b.fives = upper(5, a);
				check_upper(&b);
				break;
			}
			else if (input == 54)
			{
				if (b.sixes != -1)
				{
					continue;
				}
				b.sixes = upper(6, a);
				check_upper(&b);
				break;
			}
			else
			{
				continue;
			}
		}
		
		if (out)
		{
			printf("\nBye!\n");
			break;
		}
		if (b.sum != -1)
		{
			system("clear");
			printf("\n\n++++++++++++Yahtzee!++++++++++++\n\n\n");
			printf("Final Score\n\n");
			print_board(0, a, &b);
			printf("\nBye!\n");
			break;
		}
	}
	
	return 0;
}