/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
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

int main(int argc, char* argv[])
{
	int* rugby = 0;
	int games = 0;
	int total_score = 0;
	int equal_score = 0;
	int above_score = 0;
	int below_score = 0;
	
	printf("How many games has the rugby team played? ");
	scanf("%d", &games);
	
	rugby = malloc(games * sizeof(int));
	
	for (int i = 0; i < games; i++)
	{
		printf("-Enter score %d: ", i+1);
		scanf("%d", &rugby[i]);
		total_score += *(rugby + i);
	}
	
	printf("The average score is: %d\n", total_score / games);
	printf("Analysis:\n");
	
	for (int i = 0; i < games; i++)
	{
		printf("-Score %d, %d, ", i+1, *(rugby + i));
		if (*(rugby + i) == total_score / games)
		{
			printf("is equal to average.\n");
			equal_score++;
		}
		else if (*(rugby + i) < total_score / games)
		{
			printf("is below average.\n");
			above_score++;
		}
		else
		{
			printf("is above average.\n");
			below_score++;
		}
	}
	
	printf("Number of scores above the Average: %d\n", above_score);
	printf("Number of scores equal to the Average: %d\n", equal_score);
	printf("Number of scores below the Average: %d\n", below_score);
	
	return 0;
}