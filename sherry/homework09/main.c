/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       main.c
*  Author:     Sherry Hong
*  Student Id: 14874433
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - http://en.wikipedia.org/wiki/2048_(video_game)
*   - https://www.daniweb.com/software-development/c/threads/410155/gcc-equivalent-for-getch
*   - http://stackoverflow.com/questions/3219393
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "game.h"

int getch()
{
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}

int main(int argc, char* argv[])
{
	int board[16];
	struct game a;
	
	load(&a);
	while(1)
	{
		system("clear");
		
		if (!a.is_started)
		{
			start(board, &a);
		}
		
		printf("Welcome to 2048!\n\n");
		
		printf("Score: %d    Best: %d\n\n", a.score, a.best);
		
		print_board(board);
		
		printf("Control Keys\n[w: up] [s:down] [a:left] [d:right]\n[n:new game] [q:quit]\n");
		
		if (check_game(board) == 1)
		{
			printf("\nGame over!\n");
			break;
		}
		else if (check_game(board) == 2)
		{
			printf("\nYou win!\n");
			break;
		}
		
		char input;
		input=getch();
		
		if (input==113)
		{
			printf("Thanks for playing!\nBye!\n");
			break;
		}
		else if (input==97)
		{
			move_left(board, &a);
		}
		else if (input==100)
		{
			move_right(board, &a);
		}
		else if (input==119)
		{
			move_up(board, &a);
		}
		else if (input==115)
		{
			move_down(board, &a);
		}
		else if (input==110)
		{
			a.is_started = 0;
			a.score = 0;
		}
	}
	save(&a);
	
	return 0;
}