/********************************************************************************
 * Programming 1 (405701) / Programming for Engineering Applications (735318):
 *
 *  File:       hw08q03.c
 *  Author:     Duan Hao
 *  Student Id: 1426688
 *
 *  The following people were consulted by the author in the creation of the
 *  code submitted in this file:
 *   - None
 *
 *  The following resources were used by the author in the creation of the
 *  code submitted in this file:
 *   - http://en.wikipedia.org/wiki/Linked_list
 *   - http://stackoverflow.com/questions/10221537
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Video_Game
{
    char* title;
    char* genre;
    char* developer;
    int year;
    char* platform;
    int age;
    float price;
    char* inapp;
};

struct Game_Title_Node
{
    struct Game_Title_Node* p_next;
    struct Video_Game* data;
};

struct Game_Title_Node* g_p_first = 0;

void add_new_node(struct Video_Game* data);
void remove_node(struct Video_Game* data);
void print_all_nodes();

void print_video_game_details(struct Video_Game* game)
{
    printf("Title: %s\n", game->title);
    printf("Genre: %s\n", game->genre);
    printf("Developer: %s\n", game->developer);
    printf("Year of Release: %d\n", game->year);
    printf("Platform: %s\n", game->platform);
    printf("Lower Age Limit: %d\n", game->age);
    printf("Price: $%.2f\n", game->price);
    printf("In-app Purchases: %s\n\n", game->inapp);
}

void add_new_node(struct Video_Game* data)
{
    struct Game_Title_Node* new = malloc(sizeof(struct Game_Title_Node));
    new->data = data;
    new->p_next = g_p_first;
    g_p_first = new;
}

void remove_node(struct Video_Game* data)
{
    struct Game_Title_Node* now = g_p_first;
    struct Game_Title_Node* before = 0;
    int is_match = 0;
    while (is_match == 0)
    {
        if (now != 0)
        {
            if (now->data == data)
            {
                if (now == g_p_first)
                {
                    g_p_first = now->p_next;
                }
                else
                {
                    before->p_next = now->p_next;
                }
                free(now);
                is_match++;
            }
            else
            {
                before = now;
                now = now->p_next;
            }
        }
        else
        {
            is_match = -1;
        }
    }
    if (is_match == -1)
    {
        printf("No data matched!\n");
    }
}

void print_all_nodes()
{
    struct Game_Title_Node* now = g_p_first;
    int i = 0;
    if (g_p_first == 0)
    {
    	printf("No game title found in library!\n\n");
    }
    else
    {
    	while (now != 0)
    	{
    		i++;
    		printf("<GAME %d>\n", i);
        	print_video_game_details(now->data);
        	now = now->p_next;
    	}
    }
}

int input_d()
{
    int is_num;
    int number;
    while(1)
    {
        is_num = scanf("%d", &number);
        while(getchar()!='\n'){}
        if (is_num)
        {
            break;
        }
        else
        {
            printf("Input error!\nTry again: ");
        }
    }
    return number;
}

float input_f()
{
    int is_num;
    float number;
    while(1)
    {
        is_num = scanf("%f", &number);
        while(getchar()!='\n'){}
        if (is_num)
        {
            break;
        }
        else
        {
            printf("Input error!\nTry again: ");
        }
    }
    return number;
}

char* input_s()
{
	char string[1000];
	while(1)
	{
		int valid = scanf("%[^\n]%*c", &string);
		if (valid)
		{
			int length = strlen(string);
			char* string_return = malloc(sizeof(char)*(length+1));
			strcpy(string_return, string);
			return string_return;
		}
		else
		{
			printf("Input error!\nTry again: ");
			while(getchar()!='\n'){}
		}
	}
}

void add_new_game_title_to_library()
{
	printf("\nAdd new game title\n");
	printf("==================\n");
    struct Video_Game* game = (struct Video_Game*)malloc(sizeof(struct Video_Game));
    printf("Title: ");
    game->title = input_s();
    printf("Genre: ");
    game->genre = input_s();
    printf("Developer: ");
    game->developer = input_s();
    printf("Year: ");
    game->year = input_d();
    printf("Platform: ");
    game->platform = input_s();
    printf("Age: ");
    game->age = input_d();
    printf("Price: ");
    game->price = input_f();
    printf("Inapp: ");
    game->inapp = input_s();
    add_new_node(game);
    printf("Game title added!\n\n");
}

int main(int argc, char* argv[])
{
	int selection;
    
    while(1)
    {
    	printf("Welcome to the \"Video Game Library\" System\n");
    	printf("==========================================\n\n");
    	printf("1) View game titles in library.\n");
    	printf("2) Add game title to the library.\n");
    	printf("3) Exit.\n\n");
    	printf("Please make a selection: ");
    	selection = input_d();
    	
    	if (selection != 1 && selection != 2 && selection != 3)
    	{
    		printf("Please select from the menu!\n\n");
    		continue;
    	}
    	else if (selection == 3)
    	{
    		printf("Thanks! Bye!\n");
    		break;
    	}
    	else if (selection == 2)
    	{
    		add_new_game_title_to_library();
    	}
    	else
    	{
    		print_all_nodes();
    	}
    }
    return 0;
}