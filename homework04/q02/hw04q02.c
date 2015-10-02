/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw04q02.c
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

int is_d(char c)
{
	int i = 0;
	if (c >= 48 && c <= 57)
	{
		i = 1;
	}
	return i;
}

int is_ll(char c)
{
	int i = 0;
	if (c >= 97 && c <= 122)
	{
		i = 1;
	}
	return i;
}

int is_ul(char c)
{
	int i = 0;
	if (c >= 65 && c <= 90)
	{
		i = 1;
	}
	return i;
}

int is_w(char c)
{
	int i = 0;
	if (c == '\n' || c == 9 || c == 32)
	{
		i = 1;
	}
	return i;
}

void classify_character()
{
	char c;
	printf("Enter character: ");
	scanf("%c", &c);
	
	//This is for test reason.
	//printf("The entered character is \'%c\'\n", c);
		
	if (is_d(c))
	{
		printf("\'%c\' is a digit.\n", c);
	}
	else if (is_ll(c))
	{
		printf("\'%c\' is a lowercase letter.\n", c);
	}
	else if (is_ul(c))
	{
		printf("\'%c\' is an uppercase letter.\n", c);
	}
	else if (is_w(c))
	{
		printf("\'%c\' is whitespace.\n", c);
	}
	else
	{
		printf("\'%c\' is a symbol.\n", c);
	}
}

int main(int agrc, char* argv[])
{
	classify_character();
	return 0;
}