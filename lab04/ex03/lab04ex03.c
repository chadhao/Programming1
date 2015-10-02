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

int main(int argc, char* argv[])
{
	printf("a) Starting main function.\n");
	
	printf("b) About to start looping...\n");
	
	for (int i = 0; i < 8; i++)
	{
		printf("...Inside loop, iteration : i is currently storing: %d\n",i);
	}
	
	printf("c) Finished looping...\n");
	
	printf("d) Ending main function.\n");
	
	return 0;
}