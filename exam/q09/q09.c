
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE* file = fopen(argv[1], "r");
	int first;
	int least;
	int greatest;
	int* numbers;
	
	if (argc == 1 || file == NULL)
	{
		return 1;
	}
	else
	{
		if (!fscanf(file, "%d", &first))
		{
			return 1;
		}
		else
		{
			numbers = malloc(sizeof(int) * first);
			
			for (int i = 0; i < first; i++)
			{
				fscanf(file, "%d", &numbers[i]);
			}
			
			least = numbers[first-1];
			greatest = numbers[first-1];
			printf("%d numbers\n", first);
			
			while(first)
			{
				printf("%d\n", numbers[first-1]);
				if (numbers[first-1] < least)
				{
					least = numbers[first-1];
				}
				if (numbers[first-1] > greatest)
				{
					greatest = numbers[first-1];
				}
				first--;
			}

			printf("least: %d\n", least);
			printf("greatest: %d\n", greatest);
		}
	}
	return 0;
}