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
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int a[100];
	int b = 0;

	FILE* file_in = fopen("ex4in.bin", "rb");	
	while (fread (a+b, sizeof(int), 1, file_in) == 1)
	{
		b++;
	}
	fclose(file_in);
	
	FILE* file_out = fopen("ex4out.bin", "wb");
	for (int i = 0; i < b; i++)
	{
		a[i] = a[i] * a[i];
		printf("%d\n", a[i]);
		fwrite (a+i, sizeof(int), 1, file_out);
	}
	fclose(file_out);
	
	return 0;
}