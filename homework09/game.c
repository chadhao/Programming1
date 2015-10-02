/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       game.c
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
#include <string.h>
#include <unistd.h>

void game_init(struct game* tempGame)
{
	tempGame -> bet = 0;
	tempGame -> is_insured = 0;
	tempGame -> is_doubled = 0;	
	for (int i = 0; i < 12; i ++)
	{
		tempGame -> dealer_inhand[i] = -1;
		tempGame -> player_inhand[i] = -1;
	}
}

//betType definition
//1: bet at start of game
//2: insure
//3: double
void game_bet(int betType, struct player* tempPlayer, struct game* tempGame)
{
	if (betType == 1)
	{
		while(1)
		{
			int inputValidity;
			unsigned long tempBet;
			
			printf("Your current bet: %lu\n", tempGame -> bet);
			printf("Your current chips: %lu\n", tempPlayer -> chip);
			printf("\nPlease bet: ");
			inputValidity = scanf("%lu", &tempBet);
			while(getchar()!='\n'){}
			
			if (inputValidity)
			{
				if (tempBet > tempPlayer -> chip)
				{
					printf("You don\'t have enough chips to bet!\n");
				}
				else
				{
					tempPlayer -> chip -= tempBet;
					tempGame -> bet = tempBet;
					printf("Your current bet: %lu\n", tempGame -> bet);
					printf("Your current chips: %lu\n", tempPlayer -> chip);
					break;
				}
			}
			else
			{
				printf("Please enter a DIGIT!\n");
				while(getchar()!='\n'){}
			}
		}
	}
	else if (betType == 2)
	{
		while (1)
		{
			char tempStr[100];
			printf("\nDo you want to insure this hand? (Y/N): ");
			scanf("%[^\n]%*c", tempStr);
			
			if (strlen(tempStr))
			{
				if (tempStr[1] != '\0')
				{
					printf("Please enter Y or N!\n");
				}
				else if (tempStr[0] == 89 || tempStr[0] == 121)
				{
					if (tempPlayer -> chip >= tempGame -> bet / 2)
					{
						tempPlayer -> chip -= tempGame -> bet / 2;
						tempGame -> is_insured = 1;
						printf("This hand is insured with %lu chips!\n", tempGame -> bet / 2);
						printf("Your current bet: %lu\n", tempGame -> bet);
						printf("Your current chips: %lu\n", tempPlayer -> chip);
						break;
					}
					else
					{
						printf("You don\'t have enough chips to insure this hand!\n");
						printf("Your current bet: %lu\n", tempGame -> bet);
						printf("Your current chips: %lu\n", tempPlayer -> chip);
						break;
					}
				}
				else if (tempStr[0] == 78 || tempStr[0] == 110)
				{
					printf("You didn\'t insure this hand!\n");
					printf("Your current bet: %lu\n", tempGame -> bet);
					printf("Your current chips: %lu\n", tempPlayer -> chip);
					break;
				}
				else
				{
					printf("Please enter Y or N!\n");
				}
			}
			//else will never execute???
			else
			{
				printf("Please enter Y or N!\n");
				while(getchar()!='\n'){}
			}
		}
	}
	else if (betType == 3)
	{
		if (tempPlayer -> chip >= tempGame -> bet)
		{
			tempPlayer -> chip -= tempGame -> bet;
			tempGame -> bet += tempGame -> bet;
			tempGame -> is_doubled = 1;
			printf("You doubled this hand!\n");
			printf("Your current bet: %lu\n", tempGame -> bet);
			printf("Your current chips: %lu\n", tempPlayer -> chip);
		}
		else
		{
			printf("You don\'t have enough chips to double this hand!\n");
			printf("Your current bet: %lu\n", tempGame -> bet);
			printf("Your current chips: %lu\n", tempPlayer -> chip);
		}
	}
}

//dealType definition
//1: dealer's card
//2: player's card
void game_deal_card(int dealType, struct game* tempGame, struct deck* tempDeck)
{
	int i = 0;
	if (dealType == 1)
	{
		while(tempGame -> dealer_inhand[i] != -1)
		{
			i++;
		}
		tempGame -> dealer_inhand[i] = tempDeck -> cardNow;
		tempDeck -> cardNow++;
	}
	else
	{
		while(tempGame -> player_inhand[i] != -1)
		{
			i++;
		}
		tempGame -> player_inhand[i] = tempDeck -> cardNow;
		tempDeck -> cardNow++;
	}
}

//who definition
//1: dealer
//2: player
int game_howmanyace(int who, struct game* tempGame, struct deck* tempDeck)
{
	int counter = 0;
	int i = 0;
	if (who == 1)
	{
		while(tempGame -> dealer_inhand[i] != -1)
		{
			if (tempDeck -> oneCard[tempGame -> dealer_inhand[i]].value == 11)
			{
				counter++;
			}
			i++;
		}
	}
	else
	{	
		while(tempGame -> player_inhand[i] != -1)
		{
			if (tempDeck -> oneCard[tempGame -> player_inhand[i]].value == 11)
			{
				counter++;
			}
			i++;
		}
	}
	return counter;
}

//who definition
//1: dealer
//2: player
int game_totalvalue(int who, struct game* tempGame, struct deck* tempDeck)
{
	int total = 0;
	int i = 0;
	if (who == 1)
	{
		while(tempGame -> dealer_inhand[i] != -1)
		{
			total += tempDeck -> oneCard[tempGame -> dealer_inhand[i]].value;
			i++;
		}
		if (game_howmanyace(1, tempGame, tempDeck))
		{
			total -= (game_howmanyace(1, tempGame, tempDeck) - 1) * 10;
			if (total > 21)
			{
				total -= 10;
			}
		}
	}
	else
	{	
		while(tempGame -> player_inhand[i] != -1)
		{
			total += tempDeck -> oneCard[tempGame -> player_inhand[i]].value;
			i++;
		}
		if (game_howmanyace(2, tempGame, tempDeck))
		{
			total -= (game_howmanyace(2, tempGame, tempDeck) - 1) * 10;
			if (total > 21)
			{
				total -= 10;
			}
		}
	}
	return total;
}

//returnValue definition
//1: player blackjack
//2: player win
//3: dealer win
//4: push
int game_judge(struct game* tempGame, struct deck* tempDeck)
{
	int returnValue;
	int card_counter_dealer = 0;
	int card_counter_player = 0;
	int total_dealer = game_totalvalue(1, tempGame, tempDeck);
	int total_player = game_totalvalue(2, tempGame, tempDeck);
	while(tempGame->dealer_inhand[card_counter_dealer]!=-1){card_counter_dealer++;}
	while(tempGame->player_inhand[card_counter_player]!=-1){card_counter_player++;}
	
	if (card_counter_player == 2 && total_player == 21 && total_player > total_dealer)
	{
		returnValue = 1;
	}
	else if ((total_player <= 21 && total_player > total_dealer) || total_dealer > 21)
	{
		returnValue = 2;
	}
	else if ((total_dealer <= 21 && total_dealer > total_player) || total_player > 21)
	{
		returnValue = 3;
	}
	else
	{
		returnValue = 4;
	}
	
	return returnValue;
}

//who definition
//1: dealer
//2: player
void game_print_card(int who, struct game* tempGame, struct deck* tempDeck)
{
	int i = 0;
	int j = 0;
	
	if (who == 1)
	{
		while (tempGame -> dealer_inhand[i] != -1)
		{
			if (i)
			{
				printf(", ");
			}
			printf("%s of %s", tempDeck -> oneCard[tempGame -> dealer_inhand[i]].rank, tempDeck -> oneCard[tempGame -> dealer_inhand[i]].suit);
			i++;
		}
	}
	else
	{
		while (tempGame -> player_inhand[j] != -1)
		{
			if (j)
			{
				printf(", ");
			}
			printf("%s of %s", tempDeck -> oneCard[tempGame -> player_inhand[j]].rank, tempDeck -> oneCard[tempGame -> player_inhand[j]].suit);
			j++;
		}
	}
}

int game_end()
{
	int returnValue;
	
	while(1)
	{
		char tempStr[100];
		printf("\nDo you want to play another hand? (Y/N): ");
		scanf("%[^\n]%*c", tempStr);
			
		if (strlen(tempStr))
		{
			if (tempStr[1] != '\0')
			{
				printf("Please enter Y or N!\n");
			}
			else if (tempStr[0] == 89 || tempStr[0] == 121)
			{
				returnValue = 0;
				break;
			}
			else if (tempStr[0] == 78 || tempStr[0] == 110)
			{
				returnValue = 1;
				break;
			}
			else
			{
				printf("Please enter Y or N!\n");
			}
		}
		//else will never execute???
		else
		{
			printf("Please enter Y or N!\n");
			while(getchar()!='\n'){}
		}
	}
	
	return returnValue;
}

void game_dealer(struct game* tempGame, struct deck* tempDeck)
{
	while (game_totalvalue(1, tempGame, tempDeck) < 17)
	{
		printf("Dealer\'s cards: ");
		game_print_card(1, tempGame, tempDeck);
		printf("\n");
		printf("Dealer\'s point is %d\n", game_totalvalue(1, tempGame, tempDeck));
		sleep(1);
		game_deal_card(1, tempGame, tempDeck);
	}
	printf("Dealer\'s cards: ");
	game_print_card(1, tempGame, tempDeck);
	printf("\n");
	printf("Dealer\'s point is %d\n", game_totalvalue(1, tempGame, tempDeck));
}

void game_play(struct player* tempPlayer, struct deck* tempDeck, struct game* tempGame)
{
	int not_first_turn = 0;
	while(1)
	{
		int inputValidity;
		int select;
		
		//Check if player is blackjack
		if (game_judge(tempGame, tempDeck) == 1)
		{
			tempPlayer -> win++;
			tempPlayer -> chip += tempGame -> bet * 2.5;
			printf("You hold Blackjack!\n");
			printf("Your current chips: %lu\n", tempPlayer -> chip);
			break;
		}
		
		while(1)
		{
			if (not_first_turn)
			{
				printf("\n1.Stand  2.Hit\n");
			}
			else
			{
				printf("\n1.Double  2.Stand  3.Hit\n");
			}
			printf("Please select: ");
			inputValidity = scanf("%d", &select);
			while(getchar()!='\n'){}
			if (inputValidity)
			{
				if (select < 1 || select > 3)
				{
					printf("Please select from menu!\n");
				}
				else
				{
					if (not_first_turn)
					{
						if (select == 1)
						{
							select = 2;
						}
						else if (select == 2)
						{
							select = 3;
						}
						else
						{
							printf("Please select from menu!\n");
							continue;
						}
					}
					break;
				}
			}
			else
			{
				printf("Please enter a NUMBER!\n");
			}
		}
		
		if (select == 1)
		{
			game_bet(3, tempPlayer, tempGame);
			if (tempGame -> is_doubled)
			{
				game_deal_card(2, tempGame, tempDeck);
				printf("Your cards: ");
				game_print_card(2, tempGame, tempDeck);
				printf("\n");
				printf("Your point is %d\n", game_totalvalue(2, tempGame, tempDeck));
				if (game_totalvalue(2, tempGame, tempDeck) > 21)
				{
					tempPlayer -> lose++;
					printf("You busted!\n");
					break;
				}
				else
				{
					game_dealer(tempGame, tempDeck);
					if (game_judge(tempGame, tempDeck) == 2)
					{
						tempPlayer -> win++;
						tempPlayer -> chip += tempGame -> bet * 2;
						if (game_totalvalue(1, tempGame, tempDeck) > 21)
						{
							printf("Dealer busted!\n");
						}
						printf("You win!\n");
						printf("Your current chips: %lu\n", tempPlayer -> chip);
						break;
					}
					else if (game_judge(tempGame, tempDeck) == 3)
					{
						tempPlayer -> lose++;
						printf("Dealer wins!\n");
						printf("Your current chips: %lu\n", tempPlayer -> chip);
						break;
					}
					else
					{
						tempPlayer -> push++;
						tempPlayer -> chip += tempGame -> bet;
						printf("Push!\n");
						printf("Your current chips: %lu\n", tempPlayer -> chip);
						break;
					}
				}
			}
			continue;
		}
		else if (select == 2)
		{
			game_dealer(tempGame, tempDeck);
			if (game_judge(tempGame, tempDeck) == 2)
			{
				tempPlayer -> win++;
				tempPlayer -> chip += tempGame -> bet * 2;
				if (game_totalvalue(1, tempGame, tempDeck) > 21)
				{
					printf("Dealer busted!\n");
				}
				printf("You win!\n");
				printf("Your current chips: %lu\n", tempPlayer -> chip);
				break;
			}
			else if (game_judge(tempGame, tempDeck) == 3)
			{
				tempPlayer -> lose++;
				printf("Dealer wins!\n");
				printf("Your current chips: %lu\n", tempPlayer -> chip);
				break;
			}
			else
			{
				tempPlayer -> push++;
				tempPlayer -> chip += tempGame -> bet;
				printf("Push!\n");
				printf("Your current chips: %lu\n", tempPlayer -> chip);
				break;
			}
		}
		else
		{
			game_deal_card(2, tempGame, tempDeck);
			printf("Your cards: ");
			game_print_card(2, tempGame, tempDeck);
			printf("\n");
			printf("Your point is %d\n", game_totalvalue(2, tempGame, tempDeck));
			if (game_totalvalue(2, tempGame, tempDeck) == 21)
			{
				game_dealer(tempGame, tempDeck);
				if (game_judge(tempGame, tempDeck) == 2)
				{
					tempPlayer -> win++;
					tempPlayer -> chip += tempGame -> bet * 2;
					if (game_totalvalue(1, tempGame, tempDeck) > 21)
					{
						printf("Dealer busted!\n");
					}
					printf("You win!\n");
					printf("Your current chips: %lu\n", tempPlayer -> chip);
					break;
				}
				else
				{
					tempPlayer -> push++;
					tempPlayer -> chip += tempGame -> bet;
					printf("Push!\n");
					printf("Your current chips: %lu\n", tempPlayer -> chip);
					break;
				}
			}
			else if (game_totalvalue(2, tempGame, tempDeck) > 21)
			{
				tempPlayer -> lose++;
				printf("You busted!\n");
				printf("Your current chips: %lu\n", tempPlayer -> chip);
				break;
			}
			else
			{
				not_first_turn++;
				continue;
			}
		}
	}
}