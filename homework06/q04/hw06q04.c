/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw06q04.c
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

#include "hw06q04.h"

char get_char_at(char string[], int index)
{
	return string[index];
}

int get_string_length(char string[])
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}

void remove_last_char(char string[])
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	string[i-1] = '\0';
}

int is_palindrome(char string[])
{
	int l = get_string_length(string);
	int v = 1;
	for (int i = 0; i < l/2; i++)
	{
		if (string[i] != string[l - 1 - i])
		{
			v = 0;
		}
	}
	return v;
}