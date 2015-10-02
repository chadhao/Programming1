/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  Author:     Duan Hao / Sherry Hong
*  Student Id: 1426688 / 14874433
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - google.com
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int number_of_players = 0;
int player_now = 0;
int match_all = 0;
int card1;
int card2;
char card1_position[4];
char card2_position[4];
char names[10][64];
int matches[10];
int non_matches[10];
char poker[52][3];
char poker_deck[52][3];

int get_random(int low, int high)
{
	srand(clock());
	return (low + rand() % (high - low));
}

void get_random_poker()
{
	char origin_poker[52][3];
	char poker_suits[4] = {'h', 'd', 'c', 's'};
	char poker_ranks[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	int p = 0;
	int n = 0;
	int k = 0;
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			int l = 0;
			origin_poker[k][l] = poker_ranks[j];
			l++;
			origin_poker[k][l] = poker_suits[i];
			l++;
			origin_poker[k][l] = '\0';
			k++;
		}
	}
	
	while (p < 52)
	{
		n = get_random(0,52);
		if (origin_poker[n][0] != '\0')
		{
			for (int i = 0; i < 3; i++)
			{
				poker[p][i] = origin_poker[n][i];
			}
			origin_poker[n][0] = '\0';
			p++;
		}
		
	}
	
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			poker_deck[i][j] = ' ';
		}
		poker_deck[i][2] = '\0';
	}
}

void player()
{
	int input_validation = 0;
	while (!input_validation)
	{
		printf("Please enter the number of players: ");
		input_validation = scanf("%d", &number_of_players);
		while(getchar()!='\n'){}
		if (input_validation)
		{
			if (number_of_players > 10 || number_of_players < 1)
			{
				printf("Number of players should be no less than 1 or no more than 10.\n");
				input_validation = 0;
			}
		}
		else
		{
			printf("You should enter a NUMBER.\n");
		}
	}
	
	for (int i = 0; i < number_of_players; i++)
	{
		printf("Please enter player%d\'s name: ", i+1);
		scanf("%[^\n]%*c", &names[i]);
	}
	
	for (int i = 0; i < number_of_players; i++)
	{
		matches[i] = 0;
		non_matches[i] = 0;
	}
}

void print_deck()
{
	printf("   A    B    C    D    E    F    G    H    I    J    K    L    M\n");
	printf("  +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+\n");
	printf("1");
	for (int i = 0; i < 13; i++)
	{
		printf(" |%s|", poker_deck[i]);
	}
	printf("\n");
	printf("  +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+\n");
	printf("\n");
	
	printf("  +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+\n");
	printf("2");
	for (int i = 0; i < 13; i++)
	{
		printf(" |%s|", poker_deck[i+13]);
	}
	printf("\n");
	printf("  +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+\n");
	printf("\n");
	
	printf("  +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+\n");
	printf("3");
	for (int i = 0; i < 13; i++)
	{
		printf(" |%s|", poker_deck[i+26]);
	}
	printf("\n");
	printf("  +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+\n");
	printf("\n");
	
	printf("  +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+\n");
	printf("4");
	for (int i = 0; i < 13; i++)
	{
		printf(" |%s|", poker_deck[i+39]);
	}
	printf("\n");
	printf("  +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+\n");
	printf("\n");
}

int get_position(char x, int y)
{
	int int_x = x;
	if (int_x < 97)
	{
		return (y - 1) * 13 + (x - 65);
	}
	else
	{
		return (y - 1) * 13 + (x - 97);
	}
}

void player_status()
{
	printf("\n");
	for (int i = 0; i < number_of_players; i++)
	{
		printf("Player %d: %s\tPairs: %d\tNon-matches: %d\n", i+1, names[i], matches[i], non_matches[i]);
	}
	printf("\n");
}

int input_position(int a)
{
	int input_validation = 0;
	char x[256];
	int y;
	
	if (a == 1)
	{
		printf("Choose the first card to reveal...\n");
	}
	else
	{
		printf("Choose the second card to reveal...\n");
	}
	
	while(!input_validation)
	{
		printf("  Column? ");
		scanf("%[^\n]%*c", &x);
		if (x[1] != '\0')
		{
			printf("Please enter ONE character between \'A\' and \'M\'!\n");
		}
		else if (!(x[0] > 64 && x[0] < 78) && !(x[0] > 96 && x[0] < 110))
		{
			printf("Please enter a character between \'A\' and \'M\'!\n");
		}
		else
		{
			input_validation = 1;
		}
	}
	input_validation = 0;
	while(!input_validation)
	{
		printf("  Row? ");
		input_validation = scanf("%d", &y);
		while(getchar()!='\n'){}
		if (input_validation)
		{
			if (y < 1 || y > 4)
			{
				printf("Please enter a number between 1 and 4!\n");
				input_validation = 0;
			}
		}
		else
		{
			printf("Please enter a NUMBER between 1 and 4!\n");
		}
	}
	
	if (a == 1)
	{
		card1_position[0] = x[0];
		card1_position[1] = ',';
		card1_position[2] = y + 48;
		card1_position[3] = '\0';
	}
	else
	{
		card2_position[0] = x[0];
		card2_position[1] = ',';
		card2_position[2] = y + 48;
		card2_position[3] = '\0';
	}
	
	return get_position(x[0], y);
}

void print_result(int match, char f_r, char f_s, char s_r, char s_s)
{
	if (match == 1)
	{
		printf("Great! [%s] (%s) matches [%s] (%s)!", &poker[card1], &card1_position, &poker[card2], &card2_position);
	}
	else
	{
		printf("Sorry! [%s] (%s) does not match [%s] (%s)!", &poker[card1], &card1_position, &poker[card2], &card2_position);
	}
}

int main (int argc, char* argv[])
{
	get_random_poker();
	
	printf("Welcome to Matching Game!\n\n");
	
	player();
	
	while (match_all < 26)
	{
		int face_down = 1;
		player_status();
		print_deck();
		printf("%s\'s turn...\n\n", names[player_now]);
		while (face_down == 1)
		{
			card1=input_position(1);
			if (poker_deck[card1][0] != 32)
			{
				printf("This card is revealed, please choose another one.\n");
			}
			else
			{
				for (int i = 0; i < 2; i++)
				{
					poker_deck[card1][i] = poker[card1][i];
				}
				face_down = 0;
			}
		}
		
		face_down = 1;
		
		while (face_down == 1)
		{
			card2=input_position(2);
			if (poker_deck[card2][0] != 32)
			{
				printf("This card is revealed, please choose another one.\n");
			}
			else
			{
				for (int i = 0; i < 2; i++)
				{
					poker_deck[card2][i] = poker[card2][i];
				}
				face_down = 0;
			}
		}
		
		printf("\nRevealing cards:\n");
		
		print_deck();
		
		if (poker_deck[card1][0] == poker_deck[card2][0])
		{
			if ((poker_deck[card1][1] == 'h' && poker_deck[card2][1] == 'd') || (poker_deck[card1][1] == 'd' && poker_deck[card2][1] == 'h'))
			{
				print_result(1, poker_deck[card1][0], poker_deck[card1][1], poker_deck[card2][0], poker_deck[card2][1]);
				matches[player_now]++;
				match_all++;
				if (match_all != 25)
				{
					printf("\nStill player %s\'s turn!\n", names[player_now]);
				}
			}
			else if ((poker_deck[card1][1] == 's' && poker_deck[card2][1] == 'c') || (poker_deck[card1][1] == 'c' && poker_deck[card2][1] == 's'))
			{
				print_result(1, poker_deck[card1][0], poker_deck[card1][1], poker_deck[card2][0], poker_deck[card2][1]);
				matches[player_now]++;
				match_all++;
				if (match_all != 25)
				{
					printf("\nStill player %s\'s turn!\n", names[player_now]);
				}
			}
			else
			{
				print_result(0, poker_deck[card1][0], poker_deck[card1][1], poker_deck[card2][0], poker_deck[card2][1]);
				for (int i = 0; i < 2; i++)
				{
					poker_deck[card1][i] = ' ';
					poker_deck[card2][i] = ' ';
				}
				non_matches[player_now]++;
				player_now = (player_now + 1) % number_of_players;
				printf("\nNext player %s\'s turn!\n", names[player_now]);
			}
		}
		else
		{
			print_result(0, poker_deck[card1][0], poker_deck[card1][1], poker_deck[card2][0], poker_deck[card2][1]);
			for (int i = 0; i < 2; i++)
			{
				poker_deck[card1][i] = ' ';
				poker_deck[card2][i] = ' ';
			}
			non_matches[player_now]++;
			player_now = (player_now + 1) % number_of_players;
			printf("\nNext player %s\'s turn!\n", names[player_now]);
		}
	}
	
	printf("\n+-----Final Score-----+\n");
	int win = 0;
	int winner = 0;
	for (int i = 0; i < number_of_players; i++)
	{
		if (matches[i] > win)
		{
			win = matches[i];
			winner = i;
		}
		printf("Player %d: %s\tMatches: %d\tNon-matches: %d\n", i+1, names[i], matches[i], non_matches[i]);
	}
	printf("\nThe winner is %s!!!\n\n", names[winner]);
	printf("Thanks for playing!\n");
	return 0;
}