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
	float a[10];
	
	printf("+-----------------------------------------+\n");
	
	for (int n = 0; n < 10; n++)
	{
		a[n] = n / 2.75;
		printf("| Element at index [%d] is set to %f |\n",n , a[n]);
	}
	
	printf("+-----------------------------------------+\n");
	
	return 0;
}