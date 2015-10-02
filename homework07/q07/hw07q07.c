/********************************************************************************
 * Programming 1 (405701) / Programming for Engineering Applications (735318):
 *
 *  File:       hw07q07.c
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
 ********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** append(char** content, int* line_counter)
{
    char input_buffer[1000];
    printf("text? ");
    scanf("%[^\n]%*c", &input_buffer);
    (*line_counter)++;
    char** temp_arr = malloc((*line_counter) * sizeof(char*));
    char* temp_str = malloc(strlen(input_buffer) * sizeof(char));
    for (int i = 0; i < *line_counter-1; i++)
    {
        temp_arr[i] = content[i];
    }
    temp_arr[*line_counter-1] = temp_str;
    strcpy(temp_arr[*line_counter-1], input_buffer);
    return temp_arr;
}

char** insert(char** content, int* line_counter)
{
    int line;
    char input_buffer[1000];
    printf("line? ");
    scanf("%d", &line);
    while(getchar()!='\n'){}
    printf("text? ");
    scanf("%[^\n]%*c", &input_buffer);
    (*line_counter)++;
    char** temp_arr = malloc((*line_counter) * sizeof(char*));
    char* temp_str = malloc(strlen(input_buffer) * sizeof(char));
    for (int i = 0; i < *line_counter+1; i++)
    {
        if (i+1 < line)
        {
            temp_arr[i] = content[i];
        }
        else if (i+1 == line)
        {
            temp_arr[i] = temp_str;
        }
        else
        {
            temp_arr[i] = content[i-1];
        }
    }
    strcpy(temp_arr[line-1], input_buffer);
    return temp_arr;
}

char** delete(char** content, int* line_counter)
{
    int line;
    printf("line? ");
    scanf("%d", &line);
    while(getchar()!='\n'){}
    (*line_counter)--;
    char** temp_arr = malloc((*line_counter) * sizeof(char*));
    for (int i = 0; i < *line_counter; i++)
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
    return temp_arr;
}

char** edit_delete(char** content, int line)
{
    int start_position;
    int end_position;
    printf("position to start? ");
    scanf("%d", &start_position);
    while(getchar()!='\n'){}
    printf("position to end? ");
    scanf("%d", &end_position);
    while(getchar()!='\n'){}
    char* temp_str = malloc(((strlen(content[line-1])+1)-(end_position-start_position+1)) * sizeof(char));
    char* temp_str_origin = malloc((strlen(content[line-1])+1)*sizeof(char));
    strcpy(temp_str_origin, content[line-1]);
    for (int i = 0; i < strlen(content[line-1]); i++)
    {
        if (i < start_position)
        {
            temp_str[i] = temp_str_origin[i];
        }
        else if (i > end_position)
        {
            temp_str[i-(end_position-start_position+1)] = temp_str_origin[i];
        }
    }
    temp_str[strlen(content[line-1])-(end_position-start_position+1)] = '\0';
    content[line-1] = temp_str;
    return content;
}

char** edit_append(char** content, int line)
{
	char input_buffer[1000];
    printf("text? ");
    scanf("%[^\n]%*c", &input_buffer);
	int str_length = strlen(content[line-1]) + strlen(input_buffer);
	char* temp_str = malloc((str_length+1) * sizeof(char));
	strcpy(temp_str, content[line-1]);
	for (int i = 0; i < str_length; i++)
	{
		if (i >= strlen(content[line-1]))
		{
			temp_str[i] = input_buffer[i-strlen(content[line-1])];
		}
	}
	temp_str[str_length] = '\0';
	content[line-1] = temp_str;
	return content;
}

char** edit_insert(char** content, int line)
{
	int position;
	char input_buffer[1000];
    printf("position? ");
    scanf("%d", &position);
	while(getchar()!='\n'){}
    printf("text? ");
    scanf("%[^\n]%*c", &input_buffer);
	int str_length = strlen(content[line-1]) + strlen(input_buffer);
	char* temp_str = malloc((str_length+1) * sizeof(char));
    char* temp_str_origin = malloc((strlen(content[line-1])+1)*sizeof(char));
    strcpy(temp_str_origin, content[line-1]);
	for (int i = 0; i < str_length; i++)
	{
		if (i == position)
		{
			for (int j = 0; j < strlen(input_buffer); j++)
			{
				temp_str[i+j] = input_buffer[j];
			}
		}
		else if (i < position)
		{
			temp_str[i] = temp_str_origin[i];
		}
		else if (i >= position + strlen(input_buffer))
		{
			temp_str[i] = temp_str_origin[i - strlen(input_buffer)];
		}
	}
	temp_str[str_length] = '\0';
	content[line-1] = temp_str;
	return content;
}

char** edit(char** content, int* line_counter)
{
    char command;
    int line;
    char** temp_arr = malloc((*line_counter) * sizeof(char*));
    
    while(1)
    {
        printf("line? ");
        scanf("%d", &line);
        while(getchar()!='\n'){}
        
        printf("   ");
        for (int i = 0; i < (int)(line/10); i++)
        {
            printf(" ");
        }
        for (int i = 0; i < strlen(content[line-1]); i++)
        {
            printf("%d", i);
        }
        printf("\n%d. %s\n", line, content[line-1]);
        
        printf("command? ");
        scanf("%c", &command);
		while(getchar()!='\n'){}
        
        if (command == 'd')
        {
            temp_arr = edit_delete(content, line);
            return temp_arr;
        }
        else if (command == 'a')
        {
        	temp_arr = edit_append(content, line);
        	return temp_arr;
        }
        else if (command == 'i')
        {
       		temp_arr = edit_insert(content, line);
        	return temp_arr;
        }
        else
        {
            printf("Invalid command!\nTry \'h\' for help!\n");
        }
    }
}

void list(char** content, int* line_counter)
{
    if (*line_counter == 0)
    {
        printf("No content!\n");
    }
    else
    {
        for (int i = 0; i < *line_counter; i++)
        {
            int length = strlen(content[i]);
            char* p = malloc(sizeof(char) * (length+1));
            strcpy(p, content[i]);
            printf("%d. %s\n", i+1, p);
        }
    }
}

void help()
{
    printf("++++++++++++++++++++++++++++Command List++++++++++++++++++++++++++++\n");
    printf("a - append a line to the end of the current document\n");
    printf("i - insert a line before a specified line (giving the line number)\n");
    printf("d - delete a line\n");
    printf("l - show the current document with lines numbered\n");
    printf("e - edit a numbered line, followed by:\n");
    printf("    d - delete characters in a given range\n");
    printf("    i - insert characters in a particular position\n");
    printf("    a - append characters\n");
    printf("h - print this help message\n");
    printf("q - quit\n");
}

int main(int argc, char* argv[])
{
    char** content;
    int* line_counter = malloc(sizeof(int));
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
        else if (command == 'h')
        {
            help();
        }
        else if (command == 'a')
        {
            content = append(content, line_counter);
        }
        else if (command == 'i')
        {
            content = insert(content, line_counter);
        }
        else if (command == 'd')
        {
            content = delete(content, line_counter);
        }
        else if (command == 'l')
        {
            list(content, line_counter);
        }
        else if (command == 'e')
        {
            content = edit(content, line_counter);
        }
        else
        {
            printf("Invalid command!\nTry \'h\' for help!\n");
        }
    }
    printf("Bye!\n");
    
    return 0;
}