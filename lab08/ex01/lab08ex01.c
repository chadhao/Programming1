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

int main(int argc, char *argv[])
{
	printf("Lab08: Exercise 1: \n");
	
	int my_age = 25;
	int *my_pointer = &my_age;
	
	printf("The contents of my_age are: %d\n", my_age);
	printf("The contents of my_pointer are: %p\n", my_pointer);
	printf("The value pointed to by my_pointer is: %d\n", *my_pointer);
	
	printf("Indirection test!\n");
	
	*my_pointer = 0;
	
	printf("The contents of my_age are: %d\n", my_age);
	printf("The contents of my_pointer are: %p\n", my_pointer);
	printf("The value pointed to by my_pointer is: %d\n", *my_pointer);
	
	return 0;
}