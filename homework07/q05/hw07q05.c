/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw07q05.c
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
#include "hw07q05.h"

char* insert_space(char* string, int position, int space_len)
{
	int length = strlen(string) + space_len;
	char* string_new = malloc((length+1) * sizeof(char));
	
	for (int i = 0; i < length; i++)
	{
		if (i == position)
		{
			for (int j = 0; j < space_len; j++)
			{
				string_new[i + j] = ' ';
			}
		}
		else if (i < position)
		{
			string_new[i] = string[i];
		}
		else if (i >= position + space_len)
		{
			string_new[i] = string[i - space_len];
		}
	}
	
	string_new[length] = '\0';
	return string_new;
}

int main(int argc, char* argv[])
{
	char input_buffer[1000];
	int index;
	int num_space;
	
	printf("Please enter a string: ");
	scanf("%[^\n]%*c", &input_buffer);
	printf("How many spaces do you want to insert?: ");
	scanf("%d", &num_space);
	printf("Where do you want to put the space?: ");
	scanf("%d", &index);
	printf("The new string is \"%s\"\n", insert_space(input_buffer, index, num_space));
	
	return 0;
}