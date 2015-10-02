/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw07q03.c
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
#include <string.h>
#include <stdlib.h>

char input_buffer[1000];

char* get_user_input()
{
	int length;
	
	scanf("%s", &input_buffer);
	
	length = strlen(input_buffer);
	
	char* string = malloc((length+1) * sizeof(char));
	
	for (int i = 0; i < length; i++)
	{
		string[i] = input_buffer[i];
	}
	
	string[length] = '\0';
	
	return string;
}


int main(int argc, char* argv[])
{
	printf("First input: ");
	char *first = get_user_input();
	
	printf("Second input: ");
	char *second = get_user_input();
	
	printf("First input was %s\n", first);
	printf("Second input was %s\n", second);
	
	return 0;
}

