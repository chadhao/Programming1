/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw04q05.c
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
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

char comm;
int bag[2] = {0, 0};
int lock = 0;
int firsttime = 0;
int dead = 0;
int quit = 0;
void print_help();
void check_backpack();
void printwelcome();
int get_random(int low, int high);
char command_input();
int map0();
int map1();
int map2();
int map3();
int map4();
int guess_game();

int get_random(int low, int high)
{
	srand(time(0));
	return low + (rand() % (high - low));
}

char command_input()
{
	char i[256];
	printf("\n");
	scanf("%[^\n]%*c", &i);
	
	if (i[1] == '\0')
	{
		if (i[0] != 'f' && i[0] != 'b' && i[0] != 'l' && i[0] != 'r' && i[0] != 'c' && i[0] != 'h' && i[0] != 't' && i[0] != 'p' && i[0] != 'u' && i[0] != 'q')
		{
			printf("I don\'t understand. Try \'h\' for help.\n\n");
			return 'x';
		}
		else
		{
		return i[0];
		}
	}
	else if (i[0] == 'u' && i[2] == '\0')
	{
		if (i[1] == 'k')
		{
			if (bag[0] == 0)
			{
				printf("You don\'t have a key!\n\n");
				return 'x';
			}
			else
			{
				return 'k';
			}
		}
		else if (i[1] == 's')
		{
			if (bag[1] == 0)
			{
				printf("You don\'t have the magic stone!\n\n");
				return 'x';
			}
			else
			{
				return 's';
			}
		}
		else
		{
			printf("I don\'t understand. Try \'h\' for help.\n\n");
			return 'x';
		}
	}
	else
	{
		printf("I don\'t understand. Try \'h\' for help.\n\n");
		return 'x';
	}
}

void print_help()
{
	printf("\nCommand List\n");
	printf("f: go front\n");
	printf("b: go back\n");
	printf("l: go left\n");
	printf("r: go right\n");
	printf("c: check your backpack\n");
	printf("t: talk to someone\n");
	printf("p: pick something up\n");
	printf("u: use something\n");
	printf("h: show this command list\n");
	printf("q: quit the game\n\n");
}

void check_backpack()
{
	if (bag[0] == 0)
	{
		if (bag[1] == 0)
		{
			printf("There is nothing in your backpack.\n\n");
		}
		else
		{
			printf("There is a magic stone in your backpack.\n\n");
		}
	}
	else
	{
		if (bag[1] == 0)
		{
			printf("There is a key in your backpack.\n\n");
		}
		else
		{
			printf("There are a key and a magic stone in your backpack.\n\n");
		}
	}
}

void printwelcome(int i)
{
	if (i == 0)
	{
		printf(".\n");
		printf("..\n");
		printf("...\n");
		printf("You wake up and find yourself in a dungeon.\n");
		printf("There are four doors on each side of the room.\n");
		printf("You see that there is a backpack on the ground.\n");
		printf("You pick it up. It is empty.\n");
		printf("You are now on your own. If you need help, try \'h\'.\n\n");
	}
	else
	{
		printf("You are back at where you woke up.\n");
		printf("There are four doors on each side of the room.\n\n");
	}
}

int map0()
{
	int i = 0;
	
	if (dead == 1)
	{
		goto q0;
	}
	
	if (quit == 1)
	{
		goto q0;
	}
	
	if (firsttime == 0)
	{
		printwelcome(0);
		firsttime = 1;
	}
	else
	{
		printwelcome(1);
	}
	
l0:	do {
		comm = command_input();
	} while (comm == 'x');
	
	if (comm == 'q')
	{
		printf("See you!\n");
		return 0;
	}
	else if (comm == 'h')
	{
		print_help();
		goto l0;
	}
	else if (comm == 'c')
	{
		check_backpack();
		goto l0;
	}
	else if (comm == 't')
	{
		printf("There is no one to speak to.\n\n");
		goto l0;
	}
	else if (comm == 'p')
	{
		printf("Pick up what?\n\n");
		goto l0;
	}
	else if (comm == 'u')
	{
		if (bag[0] == 0 && bag[1] == 0)
		{
			printf("There is nothing you can use.\n\n");
			goto l0;
		}
		else if (bag[0] == 1 && bag[1] == 0)
		{
			do {
				printf("You have a key! Try \'uk\' to use it.\n\n");
				comm = command_input();
			} while (comm != 'k');
			if (lock == 0)
			{
				lock = 1;
				printf("The door to the left is unlocked!\n\n");
				goto l0;
			}
			else
			{
				lock = 0;
				printf("You locked the door to the left!\n\n");
				goto l0;
			}
		}
		else if (bag[0] == 0 && bag[1] == 1)
		{
			do {
				printf("You have a magic stone! Try \'us\' to use it.\n\n");
				comm = command_input();
			} while (comm != 's');
			printf("You stare at the glowing stone, but nothing happened.\n\n");
			goto l0;
		}
		else
		{
			do {
				printf("Try \'uk\' to use the key or \'us\' to use the magic stone.\n\n");
				comm = command_input();
			} while (comm != 'k' || comm != 's');
			if (comm == 'k')
			{
				if (lock == 0)
				{
					lock = 1;
					printf("The door to the left is unlocked!\n\n");
					goto l0;
				}
				else
				{
					lock = 0;
					printf("You locked the door to the left!\n\n");
					goto l0;
				}
			}
			else
			{
				printf("You stare at the glowing stone, but nothing happened.\n\n");
				goto l0;
			}
		}
	}
	else if (comm == 'f')
	{
		map1();
	}
	else if (comm == 'r')
	{
		map2();
	}
	else if (comm == 'b')
	{
		map3();
	}
	else if (comm == 'l')
	{
		map4();
	}
	
}

int map1()
{
	printf("You entered a room with a giant python in it.\n");
	printf("The python swallowed you in whole.\n");
	printf("You are dead.\n\n");
	dead = 1;
	map0();
	return 0;
}

int map2()
{
	if (bag[0] == 0)
	{
		printf("You found a table at the centre of the room.\n");
		printf("On the table, There is a key.\n\n");
	}
	else
	{
		printf("You found a table at the centre of the room.\n");
		printf("There is nothing on the table.\n\n");
	}
	
l2:	do {
		comm = command_input();
	} while (comm == 'x');
	
	if (comm == 'q')
	{
		printf("See you!\n");
		quit = 1;
		map0();
	}
	else if (comm == 'h')
	{
		print_help();
		goto l2;
	}
	else if (comm == 'c')
	{
		check_backpack();
		goto l2;
	}
	else if (comm == 'p')
	{
		if (bag[0] == 0)
		{
			printf("You picked up the key and put it in backpack.\n\n");
			bag[0] = 1;
		}
		else
		{
			printf("Pick up what?\n\n");
		}
		goto l2;
	}
	else if (comm == 't')
	{
		printf("There is no one to speak to.\n\n");
		goto l2;
	}
	else if (comm == 'u')
	{
		if (bag[0] == 0 && bag[1] == 0)
		{
			printf("There is nothing you can use.\n\n");
			goto l2;
		}
		else if (bag[0] == 1 && bag[1] == 0)
		{
			do {
				printf("You have a key! Try \'uk\' to use it.\n\n");
				comm = command_input();
			} while (comm != 'k');
			
			printf("There is no place to use the key here!\n\n");
			goto l2;
		}
		else if (bag[0] == 0 && bag[1] == 1)
		{
			do {
				printf("You have a magic stone! Try \'us\' to use it.\n\n");
				comm = command_input();
			} while (comm != 's');
			
			printf("You stare at the glowing stone, but nothing happened.\n\n");
			goto l2;
		}
		else
		{
			do {
				printf("Try \'uk\' to use the key or \'us\' to use the magic stone.\n\n");
				comm = command_input();
			} while (comm != 'k' || comm != 's');
			if (comm == 'k')
			{
				printf("There is no place to use the key here!\n\n");
				goto l2;
			}
			else
			{
				printf("You stare at the glowing stone, but nothing happened.\n\n");
				goto l2;
			}
		}
	}
	else if (comm == 'f')
	{
		printf("You are facing wall!\n\n");
		goto l2;
	}
	else if (comm == 'r')
	{
		printf("You are facing wall!\n\n");
		goto l2;
	}
	else if (comm == 'b')
	{
		map0();
	}
	else if (comm == 'l')
	{
		printf("You are facing wall!\n\n");
		goto l2;
	}
	return 0;
}

int map3()
{
	printf("A stone statue stands at corner.\n");
	printf("You walk towards the statue and found a hexagon hole on it.\n\n");
	
l3:	do {
		comm = command_input();
	} while (comm == 'x');
	
	if (comm == 'q')
	{
		printf("See you!\n");
		quit = 1;
		map0();
	}
	else if (comm == 'h')
	{
		print_help();
		goto l3;
	}
	else if (comm == 'c')
	{
		check_backpack();
		goto l3;
	}
	else if (comm == 'p')
	{
		printf("Pick up what?\n\n");
		goto l3;
	}
	else if (comm == 't')
	{
		printf("There is no one to speak to.\n\n");
		goto l3;
	}
	else if (comm == 'u')
	{
		if (bag[0] == 0 && bag[1] == 0)
		{
			printf("There is nothing you can use.\n\n");
			goto l3;
		}
		else if (bag[0] == 1 && bag[1] == 0)
		{
			do {
				printf("You have a key! Try \'uk\' to use it.\n\n");
				comm = command_input();
			} while (comm != 'k');
			
			printf("There is no place to use the key here!\n\n");
			goto l3;
		}
		else if (bag[0] == 0 && bag[1] == 1)
		{
			do {
				printf("You have a magic stone! Try \'us\' to use it.\n\n");
				comm = command_input();
			} while (comm != 's');
			
			printf("You found the stone is also hexagon.\n");
			printf("You tried to put it in the hole on statue.\n");
			printf("The magic stone fits the hole perfectly.\n");
			printf("The stone burst into strong white light.\n");
			printf("You fainted...\n\n");
			printf("When you wake up, you are back in the real world.\n\n");
			printf("(The End)\n");
			return 0;
		}
		else
		{
			do {
				printf("Try \'uk\' to use the key or \'us\' to use the magic stone.\n\n");
				comm = command_input();
			} while (comm != 'k' || comm != 's');
			if (comm == 'k')
			{
				printf("There is no place to use the key here!\n\n");
				goto l3;
			}
			else
			{
				printf("You found the stone is also hexagon.\n");
				printf("You tried to put it in the hole on statue.\n");
				printf("The magic stone fits the hole perfectly.\n");
				printf("The stone burst into strong white light.\n");
				printf("You fainted...\n\n");
				printf("When you wake up, you are back in the real world.\n\n");
				printf("(The End)\n");
				return 0;
			}
		}
	}
	else if (comm == 'f')
	{
		printf("You are facing wall!\n\n");
		goto l3;
	}
	else if (comm == 'r')
	{
		printf("You are facing wall!\n\n");
		goto l3;
	}
	else if (comm == 'b')
	{
		map0();
	}
	else if (comm == 'l')
	{
		printf("You are facing wall!\n\n");
		goto l3;
	}
	return 0;
}

int map4()
{
	int guess = 0;
	int random_number;
	
	if (lock == 0)
	{
		printf("The door is closed, you may need a key.\n\n");
		map0();
	}
	
	printf("A drawf is staring at you.\n\n");
	
l4:	do {
		comm = command_input();
	} while (comm == 'x');
	
	if (comm == 'q')
	{
		printf("See you!\n");
		quit = 1;
		map0();
	}
	else if (comm == 'h')
	{
		print_help();
		goto l4;
	}
	else if (comm == 'c')
	{
		check_backpack();
		goto l4;
	}
	else if (comm == 'p')
	{
		printf("Pick up what?\n\n");
		goto l4;
	}
	else if (comm == 't')
	{
		if (bag[1] == 0)
		{
			printf("\"Finally! Someone is here!!!\" The drawf screamed.\n");
			printf("\"I know you wanna get out of here.\"\n");
			printf("If you are bright enough to win me in the game, I can give you something that might help.\"\n");
			
			random_number = get_random(0,100);
			guess = guess_game(random_number);
			
			if (guess == 0)
			{
				goto l4;
			}
			else
			{
				printf("\"This is a magic stone, it can help you to get out.\"\n\n");
				bag[1] = 1;
				goto l4;
			}
		}
		else
		{
			printf("\"Good luck, my friend!\"\n\n");
			goto l4;
		}
	}
	else if (comm == 'u')
	{
		if (bag[0] == 0 && bag[1] == 0)
		{
			printf("There is nothing you can use.\n\n");
			goto l4;
		}
		else if (bag[0] == 1 && bag[1] == 0)
		{
			do {
				printf("You have a key! Try \'uk\' to use it.\n\n");
				comm = command_input();
			} while (comm != 'k');
			
			printf("There is no place to use the key here!\n\n");
			goto l4;
		}
		else if (bag[0] == 0 && bag[1] == 1)
		{
			do {
				printf("You have a magic stone! Try \'us\' to use it.\n\n");
				comm = command_input();
			} while (comm != 's');
			
			printf("You stare at the glowing stone, but nothing happened.\n\n");
			goto l4;
		}
		else
		{
			do {
				printf("Try \'uk\' to use the key or \'us\' to use the magic stone.\n\n");
				comm = command_input();
			} while (comm != 'k' || comm != 's');
			if (comm == 'k')
			{
				printf("There is no place to use the key here!\n\n");
				goto l4;
			}
			else
			{
				printf("You stare at the glowing stone, but nothing happened.\n\n");
				goto l4;
			}
		}
	}
	else if (comm == 'f')
	{
		printf("You are facing wall!\n\n");
		goto l4;
	}
	else if (comm == 'r')
	{
		printf("You are facing wall!\n\n");
		goto l4;
	}
	else if (comm == 'b')
	{
		map0();
	}
	else if (comm == 'l')
	{
		printf("You are facing wall!\n\n");
		goto l4;
	}
	return 0;
}

int guess_game(int random_number)
{
	int count = 0;
	int is_guess_wrong = 1;
	int is_input_wrong = 1;
	int guess_number;
	int scanf_number;
	
	printf("I\'m thinking of a number between 0 and 100, you have 5 times to guess.\n");
	
	while (is_guess_wrong)
	{
		if (count >= 5)
		{
			printf("\"Alright, 5 times already, sorry I can\'t help you!\"\n\n");
			return 0;
		}
		
		while (is_input_wrong)
		{
			printf("Guess time: %d\n", count + 1);
			printf("Your guess: ");
			scanf_number = scanf("%d", &guess_number);
			while(getchar()!='\n'){}
			
			if (scanf_number == 0 || guess_number < 0 || guess_number > 100)
			{
				printf("Hey! I need a number between 0 and 100!\n");
			}
			else
			{
				is_input_wrong = 0;
			}
		}
		
		is_input_wrong = 1;
		count ++;
		
		if (guess_number == random_number)
		{
			printf("\"You look smart!\"\n");
			is_guess_wrong = 0;
		}
		else if (guess_number > random_number)
		{
			printf("\"Try lower!\"\n");
		}
		else
		{
			printf("\"Try higher!\"\n");
		}
	}
	return 1;
}

int main(int agrc, char* argv[])
{
	map0();
	return 0;
}