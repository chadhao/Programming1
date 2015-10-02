/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       <hw07q07>.c
*  Author:     <Sherry Hong>
*  Student Id: <14874433>
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - None
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** append(char** content, int* lines)
{
	char input_buffer[1000];
	printf("text? ");
	scanf("%[^\n]%*c", &input_buffer);
	(*lines)++;
	char** temp_arr = malloc((*lines) * sizeof(char*));
	char* temp_str = malloc(strlen(input_buffer) * sizeof(char));
	for (int i = 0; i < *lines-1; i++)
	{
		temp_arr[i] = content[i];
	}
	temp_arr[*lines-1] = temp_str;
	strcpy(temp_arr[*lines-1], input_buffer);
	free(content);
	return temp_arr;
}

char** insert(char** content, int* lines);

char** delete(char** content, int* lines)
{
	int line;
	printf("line? ");
	scanf("%d", &line);
	while(getchar()!='\n'){}
	(*lines)--;
	char** temp_arr = malloc((*lines) * sizeof(char*));
	for (int i = 0; i < *lines; i++)
	{
		if (i+1 < line)
		{
			temp_arr[i] = content[i];
		}
		else
		{
			temp_arr[i] = content[i + 1];
		}
	}
	free(content);
	return temp_arr;
}

char** edit(char** content, int* lines);

void list(char** content, int* lines)
{
	if (*lines == 0)
	{
		printf("No content!\n");
	}
	else
	{
		for (int i = 0; i < *lines; i++)
		{
			int length = strlen(content[i]);
			char* p = malloc(sizeof(char) * (length+1));
			strcpy(p, content[i]);
			printf("%d. %s\n", i+1, p);
			free(p);
		}
	}
}

int main(int argc, char* argv[])
{
	char** content;
	int lines;
	char command;
	while(1)
	{
		printf("> ");
		scanf("%c", &command);
		while(getchar()!='\n'){}
		if (command == 'q')
		{
			break;
		}
		else if (command == 'a')
		{
			content = append(content, &lines);
		}
		/*
		else if (command == 'i')
		{
			content = insert(content, &lines);
		}
		*/
		else if (command == 'd')
		{
			content = delete(content, &lines);
		}
		else if (command == 'l')
		{
			list(content, &lines);
		}
		/*
		else if (command == 'e')
		{
			content = edit(content, &lines);
		}
		*/
		else
		{
			printf("Error!\n");
		}
	}
	printf("Bye!\n");
	return 0;
}