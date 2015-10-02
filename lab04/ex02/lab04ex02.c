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

int main(int agrc, char* argv[])
{
	printf("The size of a char is %d byte(s).\n",sizeof(char));
	printf("The size of a unsigned char is %d byte(s).\n",sizeof(unsigned char));
	printf("The size of a signed char is %d byte(s).\n",sizeof(signed char));
	printf("The size of a short is %d byte(s).\n",sizeof(short));
	printf("The size of a unsigned short is %d byte(s).\n",sizeof(unsigned short));
	printf("The size of a int is %d byte(s).\n",sizeof(int));
	printf("The size of a unsigned int is %d byte(s).\n",sizeof(unsigned int));
	printf("The size of a long is %d byte(s).\n",sizeof(long));
	printf("The size of a unsigned long is %d byte(s).\n",sizeof(unsigned long));
	printf("The size of a float is %d byte(s).\n",sizeof(float));
	printf("The size of a double is %d byte(s).\n",sizeof(double));
	printf("The size of a long double is %d byte(s).\n",sizeof(long double));
	return 0;
}