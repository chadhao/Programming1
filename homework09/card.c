/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       card.c
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
#include <stdlib.h>
#include <time.h>
#include <string.h>

int card_get_random(int low, int high)
{
	srand(clock());
	return low + (rand() % (high - low +1));
}

//This function is not working well and I don't know why.
void card_init_deck(struct deck* tempDeck)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			for (int k = 0; j < 4; k++)
			{
				strcpy(tempDeck -> oneCard[i*52+j*4+k].rank, ranks[j]);
				strcpy(tempDeck -> oneCard[i*52+j*4+k].suit, suits[k]);
				tempDeck -> oneCard[i*52+j*4+k].value = value[j];
			}
		}
	}
}

void card_shuffle(struct deck* tempDeck)
{
	int r;
	struct card tempCard;
	for (int i = 0; i < 208; i++)
	{
		r = card_get_random(0, 207);
		tempCard = tempDeck -> oneCard[i];
		tempDeck -> oneCard[i] = tempDeck -> oneCard[r];
		tempDeck -> oneCard[r] = tempCard;
	}
	tempDeck -> cardNow = 0;
}
