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
#include <string.h>

int s_to_i(char* string)
{
	int number = 0;
	int unit = 1;
	for (int i = strlen(string) - 1; i >=0; i--)
	{
		number = number + (string[i] - 48) * unit;
		unit = unit * 10;
	}
	return number;
}

int main(int argc, char* argv[])
{
	FILE* file = fopen("output.txt", "w");
	
	for (int i = 1; i < argc; i += 2)
	{
		for (int j = 0; j < s_to_i(argv[i]); j++)
		{
			if (j != 0)
			{
				fprintf(file, ", %s", argv[i+1]);
			}
			else
			{
				fprintf(file, "%s", argv[i+1]);
			}
		}
		fprintf(file, "\n");
	}
	fclose(file);
	return 0;
}