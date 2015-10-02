/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
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
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int number[10];
	int counter = 0;

	FILE* file1 = fopen("ex4in.bin", "rb");	
	while (fread (number+counter, sizeof(int), 1, file1) == 1)
	{
		counter++;
	}
	fclose(file1);
	
	FILE* file2 = fopen("ex4out.bin", "wb");
	for (int i = 0; i < counter; i++)
	{
		number[i] = number[i] * number[i];
		printf("%d\n", number[i]);
		fwrite (number+i, sizeof(int), 1, file2);
	}
	fclose(file2);
	
	return 0;
}