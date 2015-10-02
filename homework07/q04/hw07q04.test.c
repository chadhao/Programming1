
#include "hw07q04.h"
#include "p1unittesting.h"
#include <stdio.h>


void test_1()
{
	char* string = "rhinoceros";
	char* substring = get_substring(string, string + 5);
	char* expected = "rhino";
	char msg[256];
	sprintf(msg, "String is \"%s\", substring should be \"%s\"", string, expected);
	P1U_ASSERT_STRING_EQUAL(msg, substring, expected);
}


void test_2()
{
	char* string = "unexpected";
	char* substring = get_substring(string + 2, string + 8);
	char* expected = "expect";
	char msg[256];
	sprintf(msg, "String is \"%s\", substring should be \"%s\"", string, expected);
	P1U_ASSERT_STRING_EQUAL(msg, substring, expected);
}


void test_3()
{
	char* string = "banana";
	char* substring = get_substring(string + 2, string + 6);
	char* expected = "nana";
	char msg[256];
	sprintf(msg, "String is \"%s\", substring should be \"%s\"", string, expected);
	P1U_ASSERT_STRING_EQUAL(msg, substring, expected);
}


int main(int argc, char* argv[])
{
	p1u_setup();
	
	test_1();
	test_2();
	test_3();
		
	p1u_shutdown();
	return 0;
}