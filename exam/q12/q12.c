
#include <stdio.h>

#define MIN 0
#define MAX 100

int guessing(int min_now, int max_now)
{
	return min_now+(max_now-min_now)/2;
}

int is_cheating(int type, int min_now, int max_now)
{
	if (type == 1)
	{
		if(max_now <= guessing(min_now, max_now)+1)
		{
			printf("You are cheating!\n");
			return 1;
		}
	}
	else
	{
		if(min_now >= guessing(min_now, max_now)-1)
		{
			printf("You are cheating!\n");
			return 1;
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	char input[100];
	int min_now = MIN;
	int max_now = MAX;

	printf("Think of a number between 0 and 100, I will guess it!\n");
	
	while(1)
	{
		printf("I guess %d\n", guessing(min_now, max_now));
		printf("Am I right (h/l/y): ");
		scanf("%[^\n]%*c", input);
		if (input[1] != '\0')
		{
			printf("Please follow the instruction.\n");
			continue;
		}
		if (input[0] != 104 && input[0] != 108 && input[0] != 121)
		{
			printf("Please follow the instruction.\n");
			continue;
		}
		else if (input[0] == 121)
		{
			printf("Great! That\'s my favourite number too!\n");
			break;
		}
		else if (input[0] == 104)
		{
			if (is_cheating(1, min_now, max_now))
			{
				break;
			}
			min_now = guessing(min_now, max_now);
			continue;
		}
		else
		{
			if (is_cheating(2, min_now, max_now))
			{
				break;
			}
			max_now = guessing(min_now, max_now);
			continue;
		}
	}
	
	return 0;
}