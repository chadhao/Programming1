/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       player.c
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
#include <stdlib.h>

void player_name(struct player* tempPlayer)
{
	char tempStr[1000];
	
	while (1)
	{
		printf("\nPlease tell me your name!\n");
		printf("Name: ");
		scanf("%[^\n]%*c", tempStr);
		if (strlen(tempStr))
		{
			if (tempPlayer -> name != NULL)
			{
				free(tempPlayer -> name);
			}
			tempPlayer -> name = malloc(sizeof(char)*(strlen(tempStr)+1));
			strcpy(tempPlayer -> name, tempStr);
			break;
		}
		else
		{
			printf("Your name cannot be empty!\n");
			while(getchar()!='\n'){}
		}
	}
}

void player_chip(struct player* tempPlayer)
{
	int inputValidity;
	unsigned long inputTemp;
	
	while(1)
	{
		printf("\nHow many chips do you want to buy?\n");
		printf("Chips: ");
		inputValidity = scanf("%lu", &inputTemp);
		if (inputValidity)
		{
			if (inputTemp < 1)
			{
				printf("Do not try to cheat!\n");
			}
			else if (inputTemp > 10000000)
			{
				printf("You can buy 10,000,000 chips at most!\n");
			}
			else
			{
				tempPlayer -> chip = inputTemp;
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

void player_save(struct player* tempPlayer)
{
	while(1)
	{
		if (tempPlayer -> name == NULL)
		{
			break;
		}
		
		char tempStr[100];
		while(1)
		{
			printf("Do you want to save before quit? (Y/N): ");
			scanf("%[^\n]%*c", tempStr);
			if (tempStr[1] != '\0')
			{
				printf("Please enter Y or N!\n");
				continue;
			}
			else if (tempStr[0] != 78 && tempStr[0] != 89 && tempStr[0] != 110 && tempStr[0] != 121)
			{
				printf("Please enter Y or N!\n");
				continue;
			}
			break;
		}
		
		if (tempStr[0] == 89 || tempStr[0] == 121)
		{
			int length = strlen(tempPlayer -> name) + 9;
			char* filename = malloc(sizeof(char) * (length + 1));
			strcat(filename, "save/");
			strcat(filename, tempPlayer -> name);
			strcat(filename, ".txt");

			FILE* file = fopen(filename, "w+");
			free(filename);
			fprintf(file, "%s\n", tempPlayer -> name);
			fprintf(file, "%lu\n", tempPlayer -> chip);
			fprintf(file, "%d\n", tempPlayer -> win);
			fprintf(file, "%d\n", tempPlayer -> lose);
			fprintf(file, "%d\n", tempPlayer -> push);
			fclose(file);
			printf("Record saved!\n");
			break;
		}
		else
		{
			printf("Record not saved!\n");
			break;
		}
	}
}

char* player_load_read_string(FILE* file)
{
	char tempStr[100];
	int validity = fscanf(file, "%s", tempStr);
	if (validity)
	{
		char* returnStr = malloc(sizeof(char)*(strlen(tempStr)+1));
		strcpy(returnStr, tempStr);
		return returnStr;
	}
}

void player_load(struct player* tempPlayer)
{
	while(1)
	{
		char tempStr[100];
		int length;
		printf("File recorded:\n");
		system("ls -a save/");
		printf("\nPlease enter file name(with extension): ");
		scanf("%[^\n]%*c", tempStr);
		length = strlen(tempStr) + 5;
		char* filename = malloc(sizeof(char) * (length + 1));
		strcat(filename, "save/");
		strcat(filename, tempStr);
		
		FILE* file = fopen(filename, "r");
		free(filename);
		if (file != NULL)
		{
			if (tempPlayer -> name != NULL)
			{
				free(tempPlayer -> name);
			}
			tempPlayer -> name = player_load_read_string(file);
			fscanf(file, "%lu", &tempPlayer -> chip);
			fscanf(file, "%d", &tempPlayer -> win);
			fscanf(file, "%d", &tempPlayer -> lose);
			fscanf(file, "%d", &tempPlayer -> push);
			fclose(file);
			printf("Record loaded!\n");
			break;
		}
		else
		{
			printf("Open record failed!\nPlease try again and make sure you enter the correct record name.\n\n");
			fclose(file);
		}
	}
}

void player_status(struct player* tempPlayer)
{
	printf("\nPlayer name: %s\n", tempPlayer -> name);
	printf("Current chips: %lu\n", tempPlayer -> chip);
	printf("Total play times: %d\n", tempPlayer -> win+tempPlayer -> lose+tempPlayer -> push);
	printf("Win: %d time(s)\n", tempPlayer -> win);
	printf("Lose: %d time(s)\n", tempPlayer -> lose);
	printf("Push: %d time(s)\n", tempPlayer -> push);
	float wp = (float)tempPlayer->win/((float)tempPlayer->win+(float)tempPlayer->lose+(float)tempPlayer->push)*100;
	printf("Winning percentage: %.2f\%\n", wp);
}