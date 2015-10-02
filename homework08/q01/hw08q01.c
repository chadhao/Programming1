/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw08q01.c
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

int main(int argc, char* argv)
{
	struct Video_Game game1;
	struct Video_Game game2;
	struct Video_Game game3;
	
	game1.title = "Candy Crush Saga";
	game1.genre = "Match-Three Puzzle";
	game1.developer = "King";
	game1.year = 2012;
	game1.platform = "Android, iOS, Windows Phone";
	game1.age = 7;
	game1.price = 0;
	game1.inapp = "Yes";
	
	game2.title = "Halo 4";
	game2.genre = "First-Person Shooter";
	game2.developer = "343 Industries";
	game2.year = 2014;
	game2.platform = "Xbox 360, Xbox One";
	game2.age = 16;
	game2.price = 69.95;
	game2.inapp = "No";
	
	game3.title = "SimCity 4";
	game3.genre = "Economic Simulation";
	game3.developer = "Maxis";
	game3.year = 2003;
	game3.platform = "PC, Mac";
	game3.age = 0;
	game3.price = 49.99;
	game3.inapp = "No";
	
	print_video_game_details(&game1);
	print_video_game_details(&game2);
	print_video_game_details(&game3);
	
	return 0;
}