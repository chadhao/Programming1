/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       <hw07q05>.c
*  Author:     <Sherry Hong>
*  Student Id: <14874433>
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - http://stackoverflow.com/questions/6083045/scanf-n-skips-the-2nd-input-but-n-does-not-why
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw07q05.h"

char* insert_space(char* string, int position, int space_len)
{
	int new_len = strlen(string) + space_len;
	char* new_arr = malloc((new_len+1) * sizeof(char));
	for (int i = 0; i < new_len; i++)
	{
		if (i == position)
		{
			for (int j = 0; j < space_len; j++)
			{
				new_arr[i + j] = ' ';
			}
		}
		else if (i < position)
		{
			new_arr[i] = string[i];
		}
		else if (i >= position + space_len)
		{
			new_arr[i] = string[i - space_len];
		}
	}
	new_arr[new_len] = '\0';
	return new_arr;
}

int main(int argc, char* argv[])
{
	char input_buffer[1000];
	int index;
	int space;
	printf("Please enter a string: ");
	scanf("%[^\n]%*c", &input_buffer);
	printf("How many spaces?: ");
	scanf("%d", &space);
	printf("Where to put spaces?: ");
	scanf("%d", &index);
	printf("The new string is \"%s\"\n", insert_space(input_buffer, index, space));
	
	return 0;
}