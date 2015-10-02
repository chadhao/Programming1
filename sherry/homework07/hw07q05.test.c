
#include "hw07q05.h"
#include "p1unittesting.h"
#include <stdio.h>


void test_1()
{
	char* string = "helloworld";
	char* inserted = insert_space(string, 5, 3);
	char* expected = "hello   world";
	char msg[256];
	sprintf(msg, "String is \"%s\", substring should be \"%s\"", string, expected);
	P1U_ASSERT_STRING_EQUAL(msg, inserted, expected);
}


void test_2()
{
	char* string = "wait for it";
	char* inserted = insert_space(string, 0, 20);
	char* expected = "                    wait for it";
	char msg[256];
	sprintf(msg, "String is \"%s\", substring should be \"%s\"", string, expected);
	P1U_ASSERT_STRING_EQUAL(msg, inserted, expected);
}


void test_3()
{
	char* string = "The student said...";
	char* inserted = insert_space(string, 0, 10);
	char* expected = "          The student said...";
	char msg[256];
	sprintf(msg, "String is \"%s\", substring should be \"%s\"", string, expected);
	P1U_ASSERT_STRING_EQUAL(msg, inserted, expected);
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