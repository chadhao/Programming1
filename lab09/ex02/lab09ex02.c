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
	char chr_buffer;
	int counter = 1;
	FILE* file = fopen("ex2.txt", "r");
	printf("%d) ", counter);
	while(fscanf(file, "%c", &chr_buffer) == 1)
	{
		if (chr_buffer == '\n')
		{
			counter++;
			printf("\n%d) ", counter);
		}
		else
		{
			printf("%c", chr_buffer);
		}
	}
	printf("\n");
	fclose(file);
	return 0;
}