/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw06q03.c
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
********************************************************************************/

#include <stdio.h>

int nand_gate(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int nor_gate(int a, int b)
{
	if (a == 1 || b == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int xor_gate(int a, int b)
{
	if (a == b)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int xnor_gate(int a, int b)
{
	if (a == b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(int argc, char* argv[])
{
	printf(" a | b | a NAND b | a NOR b | a XOR b | a XNOR b\n");
	printf("---+---+----------+---------+---------+----------\n");	
	for(int a = 0; a < 2; a++)
	{
		for(int b = 0; b < 2; b++)
		{
			printf(" %d | %d |     %d    |    %d    |    %d     |     %d\n",
				a, b, 
				nand_gate(a, b), 
				nor_gate(a, b),
				xor_gate(a, b),
				xnor_gate(a, b));
		}
	}
	return 0;
}