/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
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
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* join_three_strings(char* s1, char* s2, char* s3)
{
	int str_len = strlen(s1) + strlen(s2) + strlen(s3) + 3;
	char* new = malloc(str_len * sizeof(char));
	
	for (int i = 0; i < strlen(s1); i++)
	{
		new[i] = s1[i];
	}
	
	new[strlen(s1)] = '-';
	
	for (int i = 0; i < strlen(s2); i++)
	{
		new[strlen(s1) + i +1] = s2[i];
	}
	
	new[strlen(s1) + strlen(s2) + 1] = '-';
	
	for (int i = 0; i < strlen(s2); i++)
	{
		new[strlen(s1) + strlen(s2) + i +2] = s3[i];
	}
	
	new[strlen(s1) + strlen(s2) + strlen(s3) + 2] = '\0';
	
	return new;
}

int main(int argc, char* argv[])
{
	char hello[] = "HELLO";
	char p1[] = "Programming 1";
	char students[] = "STUDENTS!";
	
	char* joint = join_three_strings(hello, p1, students);
	printf("JOIN RESULT 1: %s \n", joint);
	free(joint);
	joint = 0;
	
	joint = join_three_strings(p1, hello, students);
	printf("JOIN RESULT 2: %s \n", joint);
	free(joint);
	joint = 0;
	
	return (0);
}