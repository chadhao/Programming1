/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       <hw07q04>.c
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
#include <stdlib.h>
#include <stdio.h>
#include "hw07q04.h"

char* get_substring(char* start, char* end)
{
	int length = end - start;
	char* str_arr = malloc((length+1) * sizeof(char));
	for (int i = 0; i < length; i++)
	{
		str_arr[i] = start[i];
	}
	str_arr[length] = '\0';
	return str_arr;
}

int main(int argc, char* argv[])
{
	char input_buffer[1000];
	int index;
	int length;
	
	printf("Please enter a string: ");
	scanf("%s", &input_buffer);
	printf("Index of first character of substring?: ");
	scanf("%d", &index);
	printf("Length of substring?: ");
	scanf("%d", &length);
	printf("Substring is \"%s\"\n", get_substring(input_buffer+index, input_buffer+length));
	
	return 0;
}