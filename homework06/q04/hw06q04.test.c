
#include "hw06q04.h"
#include "p1unittesting.h"
#include <string.h>

void test_get_char_at()
{
	P1U_ASSERT_EQUAL("Char at offset 1 of \"hello\" is 'e'", get_char_at("hello", 1), 'e');
	P1U_ASSERT_EQUAL("Char at offset 0 of \"cat\" is 'c'", get_char_at("cat", 0), 'c');
	P1U_ASSERT_EQUAL("Char at offset 9 of \"rhinoceros\" is 's'", get_char_at("rhinoceros", 9), 's');
}

void test_get_string_length()
{
	P1U_ASSERT_EQUAL("Length of \"hello\" is 5", get_string_length("hello"), 5);
	P1U_ASSERT_EQUAL("Length of \"cat\" is 3", get_string_length("cat"), 3);
	P1U_ASSERT_EQUAL("Length of \"rhinoceros\" is 10", get_string_length("rhinoceros"), 10);
	P1U_ASSERT_EQUAL("Length of \"\" is 0", get_string_length(""), 0);
}

void test_remove_last_char()
{
	char string[100];
	strcpy(string, "hello");
	remove_last_char(string);
	P1U_ASSERT_STRING_EQUAL("\"hello\" with last char removed is \"hell\"", string, "hell");
	strcpy(string, "cat");
	remove_last_char(string);
	P1U_ASSERT_STRING_EQUAL("\"cat\" with last char removed is \"cat\"", string, "ca");
	strcpy(string, "rhinoceros");
	remove_last_char(string);
	P1U_ASSERT_STRING_EQUAL("\"rhinoceros\" with last char removed is \"rhinocero\"", string, "rhinocero");
}

void test_is_palindrome()
{
	P1U_ASSERT_TRUE("\"civic\" is a palindrome", is_palindrome("civic"));
	P1U_ASSERT_FALSE("\"civics\" is not a palindrome", is_palindrome("civics"));
	P1U_ASSERT_TRUE("\"a\" is a palindrome", is_palindrome("a"));
}


int main(int argc, char* argv[])
{
	p1u_setup();
	
	test_get_char_at();
	test_get_string_length();
	test_remove_last_char();
	test_is_palindrome();
	
	p1u_shutdown();
	return 0;
}