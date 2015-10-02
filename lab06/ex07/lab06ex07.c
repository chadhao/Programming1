/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab06ex07.c
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

#include "p1student.h"
#include "stdio.h"

void print_robot_face()
{
	printf("+-----------+\n");
	printf("|           |\n");
	printf("|  /\\   /\\  |\n");
	printf("|  \\/   \\/  |\n");
	printf("|           |\n");
	printf("|  [-=-=-]  |\n");
	printf("|           |\n");
	printf("+-----------+\n");
}

int main(int argc, char* argv[])
{
	print_robot_face();
	
	return 0;
}