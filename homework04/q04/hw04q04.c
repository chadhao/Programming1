/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw04q04.c
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

void msg_sender(char msg_type);
double set_value();
double add(double total);
double subtract(double total);
double multiply(double total);
double divide(double total);

void calculator()
{
	char comm[256];
	int i = 1;
	int c;
	double total = 0;
	printf("%f\n", total);
	
	while (i)
	{
		printf(": ");
		scanf("%[^\n]%*c", comm);
		
		if (comm[1] != '\0')
		{
			msg_sender('c');
		}
		else if (comm[0] == 113)
		{
			printf("Goodbye!\n");
			i = 0;
		}
		else if (comm[0] == 104)
		{
			msg_sender('h');
		}
		else if (comm[0] == 61)
		{
			total = set_value();
			printf("%f\n", total);
			
		}
		else if (comm[0] == 43)
		{
			total = add(total);
			printf("%f\n", total);
		}
		else if (comm[0] == 45)
		{
			total = subtract(total);
			printf("%f\n", total);
		}
		else if (comm[0] == 42)
		{
			total = multiply(total);
			printf("%f\n", total);
		}
		else if (comm[0] == 47)
		{
			total = divide(total);
			printf("%f\n", total);
		}
		else
		{
			msg_sender('c');
		}
	}
}

void msg_sender(char msg_type)
{
	if (msg_type == 110)
	{
		printf("Error, not a number.\n");
	}
	else if (msg_type == 104)
	{
		printf("Commands are:\n");
		printf("+ add\n");
		printf("- subtract\n");
		printf("* multiply\n");
		printf("/ divide\n");
		printf("= set value\n");
		printf("h print this help\n");
		printf("q quit\n");
	}
	else if (msg_type == 99)
	{
		printf("Error, not a command.\n");
		printf("Commands are:\n");
		printf("+ add\n");
		printf("- subtract\n");
		printf("* multiply\n");
		printf("/ divide\n");
		printf("= set value\n");
		printf("h print this help\n");
		printf("q quit\n");
	}
}

double add(double total)
{
	double value;
	int value_validity;
	int i = 1;
	while (i)
	{
		printf("+ ");
		value_validity = scanf("%lf", &value);
		while(getchar()!='\n'){}
		
		if (value_validity == 0)
		{
			msg_sender('n');
		}
		else
		{
			value = value + total;
			i = 0;
		}
	}
	return value;
}

double subtract(double total)
{
	double value;
	int value_validity;
	int i = 1;
	while (i)
	{
		printf("- ");
		value_validity = scanf("%lf", &value);
		while(getchar()!='\n'){}
		
		if (value_validity == 0)
		{
			msg_sender('n');
		}
		else
		{
			value = total - value;
			i = 0;
		}
	}
	return value;
}

double multiply(double total)
{
	double value;
	int value_validity;
	int i = 1;
	while (i)
	{
		printf("* ");
		value_validity = scanf("%lf", &value);
		while(getchar()!='\n'){}
		
		if (value_validity == 0)
		{
			msg_sender('n');
		}
		else
		{
			value = total * value;
			i = 0;
		}
	}
	return value;
}

double divide(double total)
{
	double value;
	int value_validity;
	int i = 1;
	while (i)
	{
		printf("/ ");
		value_validity = scanf("%lf", &value);
		while(getchar()!='\n'){}
		
		if (value_validity == 0)
		{
			msg_sender('n');
		}
		else
		{
			value = total / value;
			i = 0;
		}
	}
	return value;
}

double set_value()
{
	double value;
	int value_validity;
	int i = 1;
	while (i)
	{
		printf("= ");
		value_validity = scanf("%lf", &value);
		while(getchar()!='\n'){}
		
		if (value_validity == 0)
		{
			msg_sender('n');
		}
		else
		{
			i = 0;
		}
	}
	return value;
}

int main(int argc, char* argv[])
{
	calculator();
	return 0;
}