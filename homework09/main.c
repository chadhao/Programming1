/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       main.c
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
#include <stdio.h>
#include "bj.h"
#include "card.c"
#include "player.c"
#include "game.c"

int main(int argc, char* argv[])
{
	struct deck thisDeck;
	struct player thisPlayer;
	struct game thisGame;
	int inputValidity;
	int menu;
	int game;
	int load = 0;
	
	//Not Working!!! card_init_deck(&thisDeck);
	
	//This is the exact same algorithm used in card.c and it works great here!!! Why!!!
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				strcpy(thisDeck.oneCard[k*52+i*4+j].rank, ranks[i]);
				strcpy(thisDeck.oneCard[k*52+i*4+j].suit, suits[j]);
				thisDeck.oneCard[k*52+i*4+j].value = value[i];
			}
		}
	}
	
	card_shuffle(&thisDeck);
	thisPlayer.chip = 0;
	
	system("clear");
		
	while (1)
	{
		printf("\n\n**********BlackJack**********\n\n");
		printf(" 1. Play\n");
		printf(" 2. Load\n");
		printf(" 3. Player status\n");
		printf(" 4. Exit\n\n");
		printf("*****************************\n\n");
		while(1)
		{
			printf("Please enter menu number: ");
			inputValidity = scanf("%d", &menu);
			while(getchar()!='\n'){}
			if (inputValidity)
			{
				if (menu < 1 || menu > 4)
				{
					printf("Please select from menu!\n");
				}
				else
				{
					break;
				}
			}
			else
			{
				printf("Please enter a NUMBER!\n");
			}
		}
		
		if (menu == 4)
		{
			player_save(&thisPlayer);
			printf("Thanks for playing! Bye!\n");
			break;
		}
		else if (menu == 3)
		{
			if (thisPlayer.name == NULL)
			{
				printf("No player record.\n");
				continue;
			}
			player_status(&thisPlayer);
			continue;
		}
		else if (menu == 2)
		{
			player_load(&thisPlayer);
			continue;
		}
		else
		{
			if (thisPlayer.chip == 0)
			{
				player_name(&thisPlayer);
				player_chip(&thisPlayer);
			}
			printf("Welcome %s!\nHave fun!\n\n", thisPlayer.name);
			
			while(1)
			{
				//Deal initial cards
				game_init(&thisGame);
				if (thisDeck.cardNow > 180)
				{
					printf("\n\nShuffling...\n\n");
					card_shuffle(&thisDeck);
				}
				if (thisPlayer.chip <= 0)
				{
					printf("You are penniless!\n");
					thisPlayer.win = 0;
					thisPlayer.lose = 0;
					thisPlayer.push = 0;
					break;
				}
				game_bet(1, &thisPlayer, &thisGame);
				printf("\nDealer is dealing the cards...\n\n");
				game_deal_card(2, &thisGame, &thisDeck);
				game_deal_card(1, &thisGame, &thisDeck);
				game_deal_card(2, &thisGame, &thisDeck);
				game_deal_card(1, &thisGame, &thisDeck);
				printf("Dealer shows %s of %s\n", thisDeck.oneCard[thisGame.dealer_inhand[0]].rank, thisDeck.oneCard[thisGame.dealer_inhand[0]].suit);
				printf("Dealer\'s point is %d\n", thisDeck.oneCard[thisGame.dealer_inhand[0]].value);
				printf("Your cards: ");
				game_print_card(2, &thisGame, &thisDeck);
				printf("\n");
				printf("Your point is %d\n", game_totalvalue(2, &thisGame, &thisDeck));
				
				//Check if dealer shows an Ace
				if (thisDeck.oneCard[thisGame.dealer_inhand[0]].value == 11)
				{
					game_bet(2, &thisPlayer, &thisGame);
					if (game_totalvalue(1, &thisGame, &thisDeck) == 21 && game_judge(&thisGame, &thisDeck) != 4)
					{
						if (thisGame.is_insured)
						{
							thisPlayer.chip += thisGame.bet;
						}
						thisPlayer.lose++;
						printf("Dealer\'s cards: ");
						game_print_card(1, &thisGame, &thisDeck);
						printf("\n");
						printf("Dealer\'s point is %d\n", game_totalvalue(1, &thisGame, &thisDeck));
						printf("Dealer is BlackJack!\n");
						if (game_end())
						{
							break;
						}
						else
						{
							continue;
						}
					}
					else if (game_totalvalue(2, &thisGame, &thisDeck) == 21 && game_judge(&thisGame, &thisDeck) == 4)
					{
						thisPlayer.chip += thisGame.bet;
						thisPlayer.push++;
						printf("Push!\n");
					}
				}
				
				game_play(&thisPlayer, &thisDeck, &thisGame);
				if (game_end())
				{
					break;
				}
				continue;
			}
			continue;
		}
	}
	
	return 0;
}