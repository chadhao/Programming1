/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw04q01.c
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - http://blog.csdn.net/cbs612537/article/details/8309444
********************************************************************************/
#include <stdio.h>

int confirm()
{
	int i = 1;
	int r;
	char c[256];
	
	while (i)
	{
		printf("Confirm (y/n): ");
		scanf("%[^\n]%*c", c);
		
		if (c[1] == '\0' && (c[0] == 'y' || c[0] == 'Y'))
		{
			i = 0;
			r = 1;
		}
		else if (c[1] == '\0' && (c[0] =='n' || c[0] == 'N'))
		{
			i = 0;
			r = 0;
		}
		else
		{
			printf("Input not recognised, try again.\n");
		}
	}
	
	return r;
}

int main(int argc, char* argv[])
{
	confirm();
	return 0;
}