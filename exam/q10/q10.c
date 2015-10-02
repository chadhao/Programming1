
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
	char* first_name;
	char* last_name;
	struct person* spouse;
};

void print_person(struct person p)
{
	printf("First name: %s\n", p.first_name);
	printf("Last name: %s\n", p.last_name);
	printf("First name of spouse: %s\n", p.spouse->first_name);
	printf("Last name of spouse: %s\n", p.spouse->last_name);
}

int main(int argc, char* argv[])
{
	struct person p;
	p.first_name = malloc(sizeof(char) * (strlen("Kim")+1));
	p.first_name = "Kim";
	p.last_name = malloc(sizeof(char) * (strlen("Kardashian")+1));
	p.last_name = "Kardashian";
	p.spouse->first_name = malloc(sizeof(char) * (strlen("Kanye")+1));
	p.spouse->first_name = "Kanye";
	p.spouse->last_name = malloc(sizeof(char) * (strlen("West")+1));
	p.spouse->last_name = "West";
	print_person(p);
	return 0;
}

/*
Dont quite understand the question.
*/