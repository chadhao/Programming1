/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  Author:     <Sherry Hong>
*  Student Id: <14874433>
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - 1426688
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - None
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* file = fopen("output.txt", "w");
	for (int i = 1; i < argc; i += 2)
	{
		for (int j = 0; j < atoi(argv[i]); j++)
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