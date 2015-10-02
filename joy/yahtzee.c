/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       yahtzee.c
*  Author:     Joy Hong
*  Student Id: 
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - None
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "yahtzee.h"

int get_random(int low, int high)
{
	srand(clock());
	return low+rand()%(high-low+1);
}

void dice_random(struct dice* a)
{
	for (int i=0; i<5; i++)
	{
		if(a[i].is_hold == 0)
		{
			a[i].point = get_random(1,6);
		}
	}
}

void print_dice(struct dice* a)
{
	printf("    DICE1    DICE2    DICE3\n");
	printf("     [%d]      [%d]      [%d]\n", a[0].point, a[1].point, a[2].point);
	printf("    q:");
	if (a[0].is_hold)
	{
		printf(COLOR_RED"hold"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"roll"COLOR_RESET);
	}
	printf("   w:");
	if (a[1].is_hold)
	{
		printf(COLOR_RED"hold"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"roll"COLOR_RESET);
	}
	printf("   e:");
	if (a[2].is_hold)
	{
		printf(COLOR_RED"hold\n\n"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"roll\n\n"COLOR_RESET);
	}
	printf("        DICE4    DICE5\n");
	printf("         [%d]      [%d]\n", a[3].point, a[4].point);
	printf("        a:");
	if (a[3].is_hold)
	{
		printf(COLOR_RED"hold"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"roll"COLOR_RESET);
	}
	printf("   s:");
	if (a[4].is_hold)
	{
		printf(COLOR_RED"hold\n\n\n"COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN"roll\n\n\n"COLOR_RESET);
	}
}

void print_board(int type, struct dice* a, struct board* b)
{
	if (type)
	{
		printf("1. Ones   | ");
		if (b->ones == -1 && upper(1,a) == 0)
		{
			printf("\n");
		}
		else if (b->ones != -1)
		{
			printf(COLOR_RED"%d\n"COLOR_RESET, b->ones);
		}
		else
		{
			printf(COLOR_GREEN"%d\n"COLOR_RESET, upper(1,a));
		}
		
		printf("2. Twos   | ");
		if (b->twos == -1 && upper(2,a) == 0)
		{
			printf("\n");
		}
		else if (b->twos != -1)
		{
			printf(COLOR_RED"%d\n"COLOR_RESET, b->twos);
		}
		else
		{
			printf(COLOR_GREEN"%d\n"COLOR_RESET, upper(2,a));
		}
		
		printf("3. Threes | ");
		if (b->threes == -1 && upper(3,a) == 0)
		{
			printf("\n");
		}
		else if (b->threes != -1)
		{
			printf(COLOR_RED"%d\n"COLOR_RESET, b->threes);
		}
		else
		{
			printf(COLOR_GREEN"%d\n"COLOR_RESET, upper(3,a));
		}
		
		printf("4. Fours  | ");
		if (b->fours == -1 && upper(4,a) == 0)
		{
			printf("\n");
		}
		else if (b->fours != -1)
		{
			printf(COLOR_RED"%d\n"COLOR_RESET, b->fours);
		}
		else
		{
			printf(COLOR_GREEN"%d\n"COLOR_RESET, upper(4,a));
		}
		
		printf("5. Fives  | ");
		if (b->fives == -1 && upper(5,a) == 0)
		{
			printf("\n");
		}
		else if (b->fives != -1)
		{
			printf(COLOR_RED"%d\n"COLOR_RESET, b->fives);
		}
		else
		{
			printf(COLOR_GREEN"%d\n"COLOR_RESET, upper(5,a));
		}
		
		printf("6. Sixes  | ");
		if (b->sixes == -1 && upper(6,a) == 0)
		{
			printf("\n");
		}
		else if (b->sixes != -1)
		{
			printf(COLOR_RED"%d\n"COLOR_RESET, b->sixes);
		}
		else
		{
			printf(COLOR_GREEN"%d\n"COLOR_RESET, upper(6,a));
		}
		
		if (b->sum != -1)
		{
			printf("   Sum    | %d\n", b->sum);
		}
		else
		{
			printf("   Sum    |\n");
		}
		if (b->bonus != -1)
		{
			printf("   Bonus  | %d\n", b->bonus);
		}
		else
		{
			printf("   Bonus  |\n");
		}
	}
	else
	{
		if (b->ones != -1)
		{	
			printf("1. Ones   | %d\n", b->ones);
		}
		else
		{
			printf("1. Ones   |\n");
		}
		if (b->twos != -1)
		{
			printf("2. Twos   | %d\n", b->twos);
		}
		else
		{
			printf("2. Twos   |\n");
		}
		if (b->threes != -1)
		{
			printf("3. Threes | %d\n", b->threes);
		}
		else
		{
			printf("3. Threes |\n");
		}
		if (b->fours != -1)
		{
			printf("4. Fours  | %d\n", b->fours);
		}
		else
		{
			printf("4. Fours  |\n");
		}
		if (b->fives != -1)
		{
			printf("5. Fives  | %d\n", b->fives);
		}
		else
		{
			printf("5. Fives  |\n");
		}
		if (b->sixes != -1)
		{
			printf("6. Sixes  | %d\n", b->sixes);
		}
		else
		{
			printf("6. Sixes  |\n");
		}
		if (b->sum != -1)
		{
			printf("   Sum    | %d\n", b->sum);
		}
		else
		{
			printf("   Sum    |\n");
		}
		if (b->bonus != -1)
		{
			printf("   Bonus  | %d\n", b->bonus);
		}
		else
		{
			printf("   Bonus  |\n");
		}
	}
}	

int upper(int which, struct dice* a)
{
	int value = 0;
	
	for (int i=0; i<5; i++)
	{
		if (a[i].point == which)
		{
			value += a[i].point;
		}
	}
	
	return value;
}

void check_upper(struct board* b)
{
	if (b->sum == -1)
		if (b->ones != -1)
			if (b->twos != -1)
				if (b->threes != -1)
					if (b->fours != -1)
						if (b->fives != -1)
							if (b->sixes != -1)
								b->sum = b->ones + b->twos + b->threes + b->fours + b->fives + b->sixes;
	if (b->bonus == -1 && b->sum >= 63)
	{
		b->bonus = 35;
	}
	else if (b->bonus == -1)
	{
		b->bonus = 0;
	}
}

void change_hold(int which, struct dice* a)
{
	if (a[which].is_hold)
	{
		a[which].is_hold = 0;
	}
	else
	{
		a[which].is_hold = 1;
	}
}