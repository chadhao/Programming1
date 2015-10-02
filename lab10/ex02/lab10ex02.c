/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab10ex02.c
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

struct thing
{
	int a;
	short b;
	char c;
	double d;
	long e;
	float f;
};

void pass_by_value(struct thing input)
{
	printf("Address of input: %p\n", &input);
	printf("Address of input.a: %p\n", &input.a);
	printf("Content of input.a: %d\n", input.a);
	printf("Address of input.b: %p\n", &input.b);
	printf("Content of input.b: %d\n", input.b);
	printf("Address of input.c: %p\n", &input.c);
	printf("Content of input.c: %c\n", input.c);
	printf("Address of input.d: %p\n", &input.d);
	printf("Content of input.d: %f\n", input.d);
	printf("Address of input.e: %p\n", &input.e);
	printf("Content of input.e: %d\n", input.e);
	printf("Address of input.f: %p\n", &input.f);
	printf("Content of input.f: %f\n", input.f);
	
	input.b++;
}

void pass_by_reference(struct thing* p_input)
{
	printf("Address of p_input: %p\n", p_input);
	printf("Address of p_input.a: %p\n", &p_input->a);
	printf("Content of p_input.a: %d\n", p_input->a);
	printf("Address of p_input.b: %p\n", &p_input->b);
	printf("Content of p_input.b: %d\n", p_input->b);
	printf("Address of p_input.c: %p\n", &p_input->c);
	printf("Content of p_input.c: %c\n", p_input->c);
	printf("Address of p_input.d: %p\n", &p_input->d);
	printf("Content of p_input.d: %f\n", p_input->d);
	printf("Address of p_input.e: %p\n", &p_input->e);
	printf("Content of p_input.e: %d\n", p_input->e);
	printf("Address of p_input.f: %p\n", &p_input->f);
	printf("Content of p_input.f: %f\n", p_input->f);
	
	p_input->b++;
}

int main(int argc, char* argv[])
{
	struct thing first;
	printf("Address of first: %p\n", &first);
	
	first.a = 1;
	first.b = 1;
	first.c = '1';
	first.d = 1;
	first.e = 1;
	first.f = 1;
	
	printf("Address of first.a: %p\n", &first.a);
	printf("Content of first.a: %d\n", first.a);
	printf("Address of first.b: %p\n", &first.b);
	printf("Content of first.b: %d\n", first.b);
	printf("Address of first.c: %p\n", &first.c);
	printf("Content of first.c: %c\n", first.c);
	printf("Address of first.d: %p\n", &first.d);
	printf("Content of first.d: %f\n", first.d);
	printf("Address of first.e: %p\n", &first.e);
	printf("Content of first.e: %d\n", first.e);
	printf("Address of first.f: %p\n", &first.f);
	printf("Content of first.f: %f\n", first.f);
	
	pass_by_value(first);
	
	pass_by_reference(&first);
	
	printf("Address of first.a: %p\n", &first.a);
	printf("Content of first.a: %d\n", first.a);
	printf("Address of first.b: %p\n", &first.b);
	printf("Content of first.b: %d\n", first.b);
	printf("Address of first.c: %p\n", &first.c);
	printf("Content of first.c: %c\n", first.c);
	printf("Address of first.d: %p\n", &first.d);
	printf("Content of first.d: %f\n", first.d);
	printf("Address of first.e: %p\n", &first.e);
	printf("Content of first.e: %d\n", first.e);
	printf("Address of first.f: %p\n", &first.f);
	printf("Content of first.f: %f\n", first.f);
	
	return 0;
}