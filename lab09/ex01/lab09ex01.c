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
	FILE* file = fopen("ex1.txt", "w");
	fprintf(file, "Hello File World!");
	fclose(file);
	return 0;
}