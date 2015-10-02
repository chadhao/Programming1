/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab10ex01.c
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

int main(int argc, char* argv[])
{
	struct cat
	{
		char* name;
		int age;
		int weight;
		int tail;
	};
	
	struct cat cat_a;
	
	cat_a.name = "Whiskers";
	cat_a.age = 7;
	cat_a.weight = 8;
	cat_a.tail = 15;
	
	printf("A cat...\n");
	printf("Name: %s\n", cat_a.name);
	printf("Age: %d\n", cat_a.age);
	printf("Weight: %d\n", cat_a.weight);
	printf("Tail Length: %d\n", cat_a.tail);
	
	return 0;
}