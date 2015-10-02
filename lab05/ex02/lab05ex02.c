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
	
	char a[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	/*
	char a[52];
	
	for (int n = 0; n < 26; n++)
	{
		a[n] = n + 97;
	}
	
	for (int n = 0; n < 26; n++)
	{
		a[n + 26] = n + 65;
	}
	*/
	
	for (int n = 0; n < 52; n++)
	{
		printf("Char at index [%d] is set to '%c' its ASCII value is %d\n",n ,a[n], a[n]);
	} 
	
	
	return 0;
}