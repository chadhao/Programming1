/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       game.c
*  Author:     Sherry Hong
*  Student Id: 14874433
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
#include "game.h"

int get_random(int low, int high)
{
	srand(clock());
	return low+(rand()%(high-low+1));
}

void print_board(int board[16])
{
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			printf(" ");
			printf("[");
			if (board[i*4+j]<10)
			{
				printf("   ");
				if (board[i*4+j]!=0)
				{
					printf(COLOR_GREEN"%d"COLOR_RESET, board[i*4+j]);
				}
				else
				{
					printf(" ");
				}
			}
			else if (board[i*4+j]<100)
			{
				printf("  ");
				printf(COLOR_YELLOW"%d"COLOR_RESET, board[i*4+j]);
			}
			else if (board[i*4+j]<1000)
			{
				printf(" ");
				printf(COLOR_MAGENTA"%d"COLOR_RESET, board[i*4+j]);
			}
			else
			{
				printf(COLOR_RED"%d"COLOR_RESET, board[i*4+j]);
			}
			printf("]");
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

void random_tile(int* board)
{
	int counter = 0;
	
	for (int i=0; i<16; i++)
	{
		if (board[i] == 0)
		{
			counter++;
		}
	}
	
	while(1)
	{
		if (!counter)
		{
			break;
		}
		int r=get_random(0,15);
		if (board[r] != 0)
		{
			continue;
		}
		if (get_random(0,1))
		{
			board[r]=2;
		}
		else
		{
			board[r]=4;
		}
		break;
	}
}

void start(int* board, struct game* a)
{
	for (int i=0; i<16; i++)
	{
		board[i]=0;
	}
	a->score=0;
	a->is_started=1;
	random_tile(board);
	random_tile(board);
}

void move_right(int* board, struct game* a)
{
	for (int i=0; i<4; i++)
	{
		for (int j=1; j<4; j++)
		{
			if (board[(i+1)*4-j] != 0)
			{
				for (int k=0; k<4-j; k++)
				{
					if (board[(i+1)*4-j] == board[(i+1)*4-j-k-1])
					{
						int is_num = 0;
						for (int l=1; l<k+1; l++)
						{
							if (board[(i+1)*4-j-l] != 0)
							{
								is_num++;
							}
						}
						if (is_num)
						{
							break;
						}
						board[(i+1)*4-j] += board[(i+1)*4-j];
						board[(i+1)*4-j-k-1] = 0;
						a->score += board[(i+1)*4-j];
						if (a->best < a->score)
						{
							a->best = a->score;
						}
						break;
					}
				}
			}
		}
	}
	for (int i=0; i<4; i++)
	{
		for (int j=1; j<4; j++)
		{
			if (board[(i+1)*4-j] == 0)
			{
				for (int k=0; k<4-j; k++)
				{
					if (board[(i+1)*4-j] != board[(i+1)*4-j-k-1])
					{
						board[(i+1)*4-j] = board[(i+1)*4-j-k-1];
						board[(i+1)*4-j-k-1] = 0;
						break;
					}
				}
			}
		}
	}
	random_tile(board);
}

void move_left(int* board, struct game* a)
{
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			if (board[i*4+j] != 0)
			{
				for (int k=0; k<3-j; k++)
				{
					if (board[i*4+j] == board[i*4+j+k+1])
					{
						int is_num = 0;
						for (int l=1; l<k+1; l++)
						{
							if (board[i*4+j+l] != 0)
							{
								is_num++;
							}
						}
						if (is_num)
						{
							break;
						}
						board[i*4+j] += board[i*4+j];
						board[i*4+j+k+1] = 0;
						a->score += board[i*4+j];
						if (a->best < a->score)
						{
							a->best = a->score;
						}
						break;
					}
				}
			}
		}
	}
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			if (board[i*4+j] == 0)
			{
				for (int k=0; k<3-j; k++)
				{
					if (board[i*4+j] != board[i*4+j+k+1])
					{
						board[i*4+j] = board[i*4+j+k+1];
						board[i*4+j+k+1] = 0;
						break;
					}
				}
			}
		}
	}
	random_tile(board);
}

void move_up(int* board, struct game* a)
{
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			if (board[j*4+i] != 0)
			{
				for (int k=1; k<4-j; k++)
				{
					if (board[j*4+i] == board[j*4+i+k*4])
					{
						int is_num = 0;
						for (int l=1; l<k-1; l++)
						{
							if (board[j*4+i+l*4] != 0)
							{
								is_num++;
							}
						}
						if (is_num)
						{
							break;
						}
						board[j*4+i] += board[j*4+i];
						board[j*4+i+k*4] = 0;
						a->score += board[j*4+i];
						if (a->best < a->score)
						{
							a->best = a->score;
						}
						break;
					}
				}
			}
		}
	}
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			if (board[j*4+i] == 0)
			{
				for (int k=1; k<4-j; k++)
				{
					if (board[j*4+i] != board[j*4+i+k*4])
					{
						board[j*4+i] = board[j*4+i+k*4];
						board[j*4+i+k*4] = 0;
						break;
					}
				}
			}
		}
	}
	random_tile(board);
}

void move_down(int* board, struct game* a)
{
	for (int i=0; i<4; i++)
	{
		for (int j=3; j>=0; j--)
		{
			if (board[j*4+i] != 0)
			{
				for (int k=1; k<j+1; k++)
				{
					if (board[j*4+i] == board[j*4+i-k*4])
					{
						int is_num = 0;
						for (int l=1; l<k; l++)
						{
							if (board[j*4+i-l*4] != 0)
							{
								is_num++;
							}
						}
						if (is_num)
						{
							break;
						}
						board[j*4+i] += board[j*4+i];
						board[j*4+i-k*4] = 0;
						a->score += board[j*4+i];
						if (a->best < a->score)
						{
							a->best = a->score;
						}
						break;
					}
				}
			}
		}
	}
	for (int i=0; i<4; i++)
	{
		for (int j=3; j>=0; j--)
		{
			if (board[j*4+i] == 0)
			{
				for (int k=1; k<j+1; k++)
				{
					if (board[j*4+i] != board[j*4+i-k*4])
					{
						board[j*4+i] = board[j*4+i-k*4];
						board[j*4+i-k*4] = 0;
						break;
					}
				}
			}
		}
	}
	random_tile(board);
}

int check_game(int* board)
{
	//check win
	for (int i=0; i<16; i++)
	{
		if (board[i] == 2048)
		{
			return 2;
		}
	}
	
	//check empty space
	for (int i=0; i<16; i++)
	{
		if (board[i] == 0)
		{
			return 0;
		}
	}
	
	//check down
	for (int i=0; i<4; i++)
	{
		for (int j=3; j>=0; j--)
		{
			for (int k=1; k<j+1; k++)
			{
				if (board[j*4+i] == board[j*4+i-k*4])
				{
					int is_num = 0;
					for (int l=1; l<k; l++)
					{
						if (board[j*4+i-l*4] != 0)
						{
							is_num++;
						}
					}
					if (is_num)
					{
						break;
					}
					return 0;
				}
			}
		}
	}
	
	//check up
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			for (int k=1; k<4-j; k++)
			{
				if (board[j*4+i] == board[j*4+i+k*4])
				{
					int is_num = 0;
					for (int l=1; l<k-1; l++)
					{
						if (board[j*4+i+l*4] != 0)
						{
							is_num++;
						}
					}
					if (is_num)
					{
						break;
					}
					return 0;
				}
			}
		}
	}
	
	//check left
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			for (int k=0; k<3-j; k++)
			{
				if (board[i*4+j] == board[i*4+j+k+1])
				{
					int is_num = 0;
					for (int l=1; l<k+1; l++)
					{
						if (board[i*4+j+l] != 0)
						{
							is_num++;
						}
					}
					if (is_num)
					{
						break;
					}
					return 0;
				}
			}
		}
	}
	
	//check right
	for (int i=0; i<4; i++)
	{
		for (int j=1; j<4; j++)
		{
			for (int k=0; k<4-j; k++)
			{
				if (board[(i+1)*4-j] == board[(i+1)*4-j-k-1])
				{
					int is_num = 0;
					for (int l=1; l<k+1; l++)
					{
						if (board[(i+1)*4-j-l] != 0)
						{
							is_num++;
						}
					}
					if (is_num)
					{
						break;
					}
					return 0;
				}
			}
		}
	}
	
	return 1;
}

void save(struct game* a)
{
	FILE* file = fopen("best.txt", "w+");
	fprintf(file, "%d", a->best);
	fclose(file);
}

void load(struct game* a)
{
	FILE* file = fopen("best.txt", "r");
	if (file != NULL)
	{
		fscanf(file, "%d", &a->best);
		fclose(file);
	}
}