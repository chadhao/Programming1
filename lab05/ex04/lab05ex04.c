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

int string_length(char the_word[])
{
	int count = 0;
	while (the_word[count] != '\0')
	{
		count++;
	}
	return count;
}

int count_lowercase_chars(char the_word[])
{
	int count = 0;
	int char_count = 0;
	while (the_word[count] != '\0')
	{
		if (the_word[count] >= 97 && the_word[count] <= 122)
		{
			char_count++;
		}
		count++;
	}
	return char_count;
}

int count_uppercase_chars(char the_word[])
{
	int count = 0;
	int char_count = 0;
	while (the_word[count] != '\0')
	{
		if (the_word[count] >= 65 && the_word[count] <= 90)
		{
			char_count++;
		}
		count++;
	}
	return char_count;
}

int count_non_alphabet_chars(char the_word[])
{
	int count = 0;
	int char_count = 0;
	while (the_word[count] != '\0')
	{
		if (!(the_word[count] >= 65 && the_word[count] <= 90) && !(the_word[count] >= 97 && the_word[count] <= 122))
		{
			char_count++;
		}
		count++;
	}
	return char_count;
}

int main(int argc, char* argv[])
{
	char words[][6] = { "Hello", "WoRlD", "And", "Hi!!!", "P1", "Lab05", "*Fun*", "what?", "HELP", "?!?!!" };
	
	int length_results[10];
	int lowercase_results[10];
	int uppercase_results[10];
	int non_alphabet_results[10];
	
	for (int i = 0; i < 10; i++)
	{
		length_results[i] = string_length(words[i]);
		lowercase_results[i] = count_lowercase_chars(words[i]);
		uppercase_results[i] = count_uppercase_chars(words[i]);
		non_alphabet_results[i] = count_non_alphabet_chars(words[i]);
	}
	
	for (int i = 0; i < 10; i++)
	{
		printf("\"%s\" contains ", words[i]);
		printf("%d lower-case, ", lowercase_results[i]);
		printf("%d upper-case, ", uppercase_results[i]);
		printf("and %d non-alphabet glyphs.\n", non_alphabet_results[i]);
	}
	
	return 0;
}